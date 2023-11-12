const { MyAlgoWallet } = require('@randlabs/myalgo-connect');

const myAlgoWallet = new MyAlgo();

myAlgoWallet.connect()
.then((accounts) => {
    // Accounts is an array that has all public addresses shared by the user
})
.catch((err) => {
    // Error
});