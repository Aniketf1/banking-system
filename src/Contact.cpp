//
// Created by Adrien Le Roy on 18/05/2016.
//

#include "Contact.h"
using namespace std;
/**
 * BankAccount implementation
 */

string Contact::_dbTable = "contact";

Contact::Contact(unsigned int idUser, unsigned int idAdvisor, std::string message) {
    this->_idClient=idUser;
    this->_idAdvisor=idAdvisor;
    this->_message = message;
}

Contact::Contact(unsigned int id) // Get a User from an ID provided by DB
{
    map<string, string> data = BaseModel::getById(_dbTable, id);

    if (!data.empty()) {
        _id = id;
        _idClient = stoi(data["id_client"]);
        _idAdvisor = stoi(data["id_advisor"]);
        _message = data["message"];
    }
    else {
        throw invalid_argument("The id of the bank account does not exist.");
    }
}

bool Contact::save(){
    int res = BaseModel::save(_dbTable, {
            {"id", {to_string(_id), "int"}},
            {"id_client", {to_string(_idClient),"int"}},
            {"id_advisor", {to_string(_idAdvisor), "int"}},
            {"message", {_message, "string"}},
    });
    if (_id == 0)
    {
        _id = res["id"];
    }

    return (bool) res;
}