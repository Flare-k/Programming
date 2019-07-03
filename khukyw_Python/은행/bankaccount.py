import time
 
accountNo = 999
 
class BankAccount(object):
    @classmethod
    def createAccountNo(cls):
        global accountNo
        if accountNo < 999 or accountNo > 9999:
            print('더이상 계좌개설을 할 수 없습니다.')
            return ''
         
        accountNo = accountNo + 1
        return str(accountNo)
     
    def __init__(self, balance):
        self.__accountNo = BankAccount.createAccountNo()
        self.__balance = balance
        d = time.localtime()
        self.__currentData = '%s/%s/%s' % (d.tm_year, d.tm_mon, d.tm_mday)
         
    def displayAccountInfo(self):
        print('-. 계좌번호 : %d\n-. 잔액 : %d 원\n-. 개설 날짜 : %s\n' % (self.__accountNo, self.__balance, self.__currentData))
         
    @property
    def accountNo(self):
        return self.__accountNo
     
    @property
    def balance(self):
        return self.__balance
 
    @balance.setter
    def balance(self, value):
        self.__balance = value
     
    @property
    def currentData(self):
        return self.__currentData        


#출처: https://uzooin.tistory.com/155 [뚱땡이 우주인]