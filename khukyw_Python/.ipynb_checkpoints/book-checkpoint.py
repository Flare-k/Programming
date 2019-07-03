{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": [
    "class Book:\n",
    "    def __init__(self, title, authors, publisher, isbn, price):\n",
    "        \n",
    "        self.title = title\n",
    "        self.authors = authors[:]\n",
    "        self.publisher = publisher\n",
    "        self.ISBN = isbn\n",
    "        self.price = price\n",
    "    def num_authors(self):\n",
    "        return len(self.authors)\n",
    "    \n",
    "    def __str__(self):\n",
    "        rep = \" Title: {0}\\n Authors: {1}\\n Publisher: {2}\\n ISBN: {3}\\n Price: {4}\".format(self.title, self.authors, self.publisher, self.ISBN, self.price)\n",
    "        return rep\n",
    "    \n",
    "    def __eq__(self, other):\n",
    "        return self.ISBN == other.ISBN"
   ]
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.7.3"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 2
}
