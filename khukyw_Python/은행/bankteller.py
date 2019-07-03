from human import Human
from customer import Customer
from bankaccount import BankAccount
 
GENDER_TBL = {'M' : '남자', 'F' : '여자', 'C' : '컴퓨터', 'N' : '성별모름'}
class BankTeller(Human):
    def __init__(self, empID, name, age, gender):
        super().__init__(name, age, gender)
        self.__empID = empID   
        self.__customerList = []
         
    def _findCustomer(self, custId, passwd):
        for customer in self.__customerList:
            if customer.custId == custId and customer.passwd == passwd:
                return customer
             
        return None
     
    def existCustomerId(self, cusId):
        for customer in self.__customerList:
            if customer.custId == cusId:
                return True
             
        return False
         
    def registerCustomer(self, cusId, passwd, name, age=0, gender=''):
        if self.existCustomerId(cusId):
            print('동일한 ID가 존재 합니다. Id를 다시 입력 해주세요')   
            return False
 
        self.__customerList.append(Customer(cusId, passwd, name, age, gender))
        print('고객 등록이 정상적으로 처리 되었습니다. 고객 ID : %s' % cusId)
        return True
     
    def searchCustomer(self, custId, passwd):
        customer = self._findCustomer(custId, passwd)
        if customer is not None:
            print('-. 아이디 : %s\n-. 비밀번호: %s\n-. 이름: %s\n-. 나이: %d\n-. 성별: %s' %(customer.custId, customer.passwd, customer.name, customer.age, GENDER_TBL[customer.gender]))
            if customer.account is not None:
                print('-. 계좌번호 : %s (계좌 개설일 : %s)' % (customer.account.accountNo, customer.account.currentData))
        else:
            print('일치하는 고객의 정보가 없습니다')
     
    def createAccount(self, custId, passwd, balance):
        customer = self._findCustomer(custId,passwd)
        if customer is not None:
            customer.account = BankAccount(balance)          
            print('계좌가 성공적으로 개설되었습니다')
        else:
            print('아이디(%s) 고객님의 계좌가 이미 개설되어 있습니다.' % custId)
 
    def searchAccount(self, custId, passwd):
        customer = self._findCustomer(custId, passwd)
        if customer is not None and customer.account is not None:
            print('-. 이름 : %s(아이디 : %s)' % (customer.name, customer.custId))
            print('-. 계좌번호 : %s\n-. 잔액 : %d\n-. 계좌 개설일: %s\n' % (customer.account.accountNo, customer.account.balance, customer.account.currentData))            
        else:
            print('일치하는 고객의 정보가 없습니다')
     
    def _check_account_input_range(self, v):
        if v < 1000:
            print('1000원 이하의 금액은 입출금 할 수 없습니다.')
        elif v > 10000000:
            print('백만원 이상의 금액은 입출금 할 수 없습니다.')
        else:
            return True
         
        return False
             
     
    def depositAccount(self, custId, passwd, value):
        if self._check_account_input_range(value) is False:
            return None
 
        customer = self._findCustomer(custId, passwd)
 
        if customer is None:
            print('일치하는 고객 정보가 없습니다. 아이디와 비밀번호를 확인하세요') 
        elif customer.account is None:
            print('고객의 계좌가 없습니다. 계좌를 개설하세요')
        else:
            customer.account.balance =customer.account.balance +  value
            print('입금이 정상적으로 처리 되었습니다. (현재 잔고 : %d)' % customer.account.balance)
 
    def withdrawAccount(self, custId, passwd, value):
        if self._check_account_input_range(value) is False:
            return None
 
        customer = self._findCustomer(custId, passwd)
 
        if customer is None:
            print('일치하는 고객 정보가 없습니다. 아이디와 비밀번호를 확인하세요') 
        elif customer.account is None:
            print('고객의 계좌가 없습니다. 계좌를 개설하세요')
        elif customer.account.balance < value:
            print('잔고가 부족합니다. (현재잔고 : %d)' % customer.account.balance)            
        else:
            customer.account.balance =customer.account.balance - value
            print('출금이 정상적으로 처리 되었습니다. (현재 잔고 : %d)' % customer.account.balance)            

if __name__ == '__main__':
    bank_teller = BankTeller('LT1234', 'LG Teller', 1, 'C')
    bank_teller.registerCustomer('1234', '1234', 'hong', 1, 'M')
    bank_teller.searchCustomer('1234', '1234')


#출처: https://uzooin.tistory.com/155 [뚱땡이 우주인]