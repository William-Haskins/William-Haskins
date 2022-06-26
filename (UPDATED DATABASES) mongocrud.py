import pymongo
import pprint

from pymongo import MongoClient
from bson.objectid import ObjectId


class MongoCRUDs(object):
    """ CRUD operations for a Mongo database. """

    # init as in Initializing. For the Mongo Client.
    # Mongo ip example: 'mongodb://%s:%s@localhost:12345'
    def __init__(self, mongoip, mongoData, mongoFile, username, password):
        self.client = MongoClient(mongoip % (username, password))
        self.database = self.client.mongoData
	self.file = mongoFile
    
    #Type of data should be a dictionary matching the document's design.
    def create(self, data): 
        if data is not None:
            self.database.file.insert_one(data)
        else:
            raise Exception("Nothing to save, because data parameter is empty.\n")
            
        
    def readDocument(self, data):
	return self.database.file.find_one(data)        

            
    def readAllDocuments(self, data):
        for i in self.database.file.find(data):
            print (i)

        
    def updateDocument(self, data, newData):
        if data is not None:
            if newData is not None:
                updatedData = { "$set": newData }
                self.database.file.update_many(data,updatedData)
                print("Updating. . .\n")
                for i in self.database.file.find(data):
                    print (i)
        else:
            raise Exception("Cannot update, because a parameter is empty.\n")
                
        
    def deleteDocument(self, data):
        if data is not None:
            deletion = self.database.file.delete_many(data)
            print("Deleted", deletion.deleted_count, "data. \n")
        else:
            raise Exception("Cannot delete, because data parameter is empty.\n")
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        