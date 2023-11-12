# Sample PyTeal script (extremely simplified)
from pyteal import *

handle_creation = Seq(App.globalPut(Bytes("Count"), Int(0)), Approve())

def approval_program():
    on_initialization = Seq([
        # On initialization, set 2 global variables
        App.localPut(Int(0), Bytes("passportID"), Int(0)),
        App.localPut(Int(0), Bytes("passportData"), Bytes("")),
        Return(Int(1))
    ])

    on_call = Seq([
        # On call, check for different user inputs and handle them appropriately
        scratchCount = ScratchVar(TealType.uint64)
        scratchCount.store(App.globalGet(Bytes("Count")))

        Cond(
            [Txn.application_id() == Int(0), Seq([
                # If creating new passport, store user's passport data
                App.localPut(scratchCount, Bytes("passportData"), Txn.application_args[1]),
                App.globalPut(Bytes("Count"), scratchCount.load() + Int(1)),
                Return(Int(1))
            ])],
            [Txn.application_id() != Int(0), Seq([
                # If fetching passport data, return the stored data
                App.localGet(Int(0), Bytes("passportData")),
                Return(Int(1))
            ])]
        )
    ])

    return If(Txn.application_type() == TxnType.ApplicationCall, on_call, on_initialization)

# Compile the program
compiled_teal = compileTeal(approval_program(), mode=Mode.Application)
print(compiled_teal)
