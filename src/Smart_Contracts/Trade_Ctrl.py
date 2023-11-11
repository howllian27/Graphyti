from pyteal import *

router = Router(
    "Trade_Ctrl",
    BareCallActions(
        no_op=OnCompleteAction.create_only(Approve()),
    ),
)

TRADE_ITEM_ID = Int(1000000)  # 1 million microAlgos = 1 Algo


@router.method
def IMPORT(receiver: abi.Account, *, output: abi.Address):
    return Seq(
        InnerTxnBuilder.Execute(
            {
                TxnField.type_enum: TxnType.Payment,
                TxnField.amount: TRADE_ITEM_ID,
                TxnField.receiver: receiver.address(),
            }
        ),
        output.set(receiver.address()),
    )


@router.method
def EXPORT(payment: abi.PaymentTransaction):
    return Seq(
        Assert(payment.get().receiver() == Global.current_application_address()),
        Assert(payment.get().amount() >= (TRADE_ITEM_ID)),  # cover txn cost
        App.globalPut(Bytes("exporter"), payment.get().sender()),
    )


@router.method
def get_exporter(*, output: abi.Address):
    return output.set(App.globalGet(Bytes("exporter")))


if __name__ == "__main__":
    import os
    import json

    path = os.path.dirname(os.path.abspath(__file__))
    approval, clear, contract = router.compile_program(version=8)

    # Dump out the contract as json that can be read in by any of the SDKs
    with open(os.path.join(path, "artifacts/contract.json"), "w") as f:
        f.write(json.dumps(contract.dictify(), indent=2))

    # Write out the approval and clear programs
    with open(os.path.join(path, "artifacts/approval.teal"), "w") as f:
        f.write(approval)

    with open(os.path.join(path, "artifacts/clear.teal"), "w") as f:
        f.write(clear)