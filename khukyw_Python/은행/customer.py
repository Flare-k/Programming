from human import Human
 
class Customer(Human):
    def __init__(self, custId, passwd, name, age, gender):
        super().__init__(name, age, gender)
        self.__custId = custId
        self.__passwd = passwd
        self.__account = None
         
    @property
    def custId(self):
        return self.__custId
     
    @property
    def passwd(self):
        return self.__passwd
 
    @property
    def account(self):
        return self.__account
 
    @account.setter
    def account(self, account):
        self.__account = account       
        
if __name__ == '__main__':
    c = Customer('1234', '1234', 'AAA', 1, 'M')
    print(c.custId)
    print(c.passwd)


#출처: https://uzooin.tistory.com/155 [뚱땡이 우주인]