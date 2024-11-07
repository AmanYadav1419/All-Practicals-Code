//SPDX-License-Identifier:Unlicensed

pragma solidity ^0.8.0;

contract studentReg{

    struct Student{
        string name;
        uint256 age;
    }

    Student[]private students;

    event RecieveEther(address indexed sender,uint256 value);

    receive() external payable {

        emit RecieveEther(msg.sender,msg.value);
    }

    fallback() external payable{

        emit RecieveEther(msg.sender, msg.value);
    }

    function addStudent(string memory name,uint256 age)public{

        students.push(Student(name,age));
    }

    function getStudent(uint256 index)public view returns(string memory name,uint256 age){

        require(index<students.length,"Not Found");
        return(students[index].name,students[index].age);
    }

    function getstudentsCount()public view returns(uint256){

        return(students.length);
    }

}