import pymongo
import pprint

from pymongo import MongoClient
from bson.objectid import ObjectId


class AnimalShelter(object):
    """ CRUD operations for the animal collection in Mongo || ("accuser", "password")"""
    
    def __init__(self, username, password):
        # init as in Initializing. For the Mongo Client.
        self.client = MongoClient('mongodb://%s:%s@localhost:37127' % (username, password))
        self.database = self.client.AAC
    
    def create(self, data): #Type of data should be a dictionary matching the document's design.
        if data is not None:
            self.database.animals.insert_one(data)
        else:
            raise Exception("Nothing to save, because data parameter is empty.\n")
            
        
    def readDocument(self, data):
        for x in self.database.animals.find(data):
            print (x)
            
    def getDocument(self, data):
        return self.database.animals.find_one(data)

        
    def updateDocument(self, data, newData):
        if data is not None:
            if newData is not None:
                updatedData = { "$set": newData }
                self.database.animals.update_many(data,updatedData)
                print("Updating. . .\n")
                for x in self.database.animals.find(data):
                    print (x)
        else:
            raise Exception("Cannot update, because a parameter is empty.\n")
                
        
    def deleteDocument(self, data):
        if data is not None:
            deletion = self.database.animals.delete_many(data)
            print("Deleted", deletion.deleted_count, "data. \n")
        else:
            raise Exception("Cannot delete, because data parameter is empty.\n")
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        