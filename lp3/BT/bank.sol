//SPDX-License-Identifier:Unlicensed

pragma solidity ^0.8.0;

contract Bank{

    mapping(address=>uint256) private balances;

    function createAccount()public{
        balances[msg.sender]=0;
    }

    function getBalance()public view returns(uint256){
        return(balances[msg.sender]);
    }

    function deposit(uint256 amount)public payable{
       balances[msg.sender]+=amount;
    }

    function withdraw(uint256 amount)public{
        require(balances[msg.sender] >= amount,"Insufficient amount");
        balances[msg.sender]-=amount;
    }

    function transfer(uint256 amount,address reciever)public{
        require(balances[msg.sender] >= amount,"Insufficient amount");
        balances[msg.sender]-=amount;
        balances[reciever]+=amount;
    }
    
}