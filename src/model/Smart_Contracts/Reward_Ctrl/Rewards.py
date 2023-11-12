from pyteal import *

user_scores = App.localGetEx(Int(0), Txn.sender(), Bytes("score"))
user_settings = App.localGetEx(Int(0), Txn.sender(), Bytes("settings"))

@App.method(on_call=True)
def calculate_rewards():
    community_votes = App.globalGet(Bytes("community_votes"))
    complexity_score = App.localGetEx(Int(0), Txn.sender(), Bytes("complexity")).value

    total_score = community_votes / 2 + complexity_score / 2

    return Seq(
        App.localPut(Int(0), Txn.sender(), Bytes("score"), total_score),
        App.localPut(Int(0), Txn.sender(), Bytes("rewards"), total_score * 100),  # Adjust multiplier as needed
        Int(1)  # Approve the transaction
    )

@App.method(on_call=True)
def vote_settings():
    user_to_vote = Txn.accounts[1]

    return Seq(
        App.globalPut(Bytes("community_votes"), App.globalGet(Bytes("community_votes")) + 1),
        App.localPut(Int(0), user_to_vote, Bytes("community_votes"), App.localGetEx(Int(0), user_to_vote, Bytes("community_votes")).value + 1),
        Int(1)  # Approve the transaction
    )
