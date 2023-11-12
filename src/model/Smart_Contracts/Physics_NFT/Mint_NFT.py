from pyteal import *

# Algorand SDK (using Python SDK)
from algosdk import transaction

# Connect to Algorand node
# Replace 'your-algod-address' and 'your-algod-token' with actual values
algod_address = 'your-algod-address'
algod_token = 'your-algod-token'
algod_client = algosdk.algod.AlgodClient(algod_token, algod_address)

# Your compiled PyTeal approval program
approval_program_bytes = bytes.fromhex(approval_program)

# Sender's address
sender = 'your-sender-address'

# Create the transaction to mint the NFT
txn = transaction.AssetConfigTxn(
    sender,
    fee=1000,
    first=1,
    last=1,
    genesis_hash=b'your-genesis-hash',
    total=1,  # Total supply of the NFT
    default_frozen=False,
    unit_name='PHYS',
    asset_name='PhysicsNFT',
    manager=sender,
    reserve=sender,
    freeze=sender,
    clawback=sender,
    url='https://your-nft-metadata-url',
    decimals=0,
    strict_empty_address_check=False,
    metadata_hash=approval_program_bytes
)

# Sign the transaction
signed_txn = txn.sign(b'your-sender-private-key')

# Submit the transaction to the network
algod_client.send_transaction(signed_txn)
