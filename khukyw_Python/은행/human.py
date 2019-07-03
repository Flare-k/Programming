class Human(object):
    def __init__(self, name, age, gender):
        self.__name = name
        self.__age = age
        self.__gender = gender
 
    @property
    def name(self):
        return self.__name
     
    @property
    def age(self):
        return self.__age
     
    @property
    def gender(self):
        return self.__gender


#출처: https://uzooin.tistory.com/155 [뚱땡이 우주인]