########################################################################################################################
#Author:Denzell Barnett
#Purpose: Generate an ordered list (smallest to largest). See problem statement.
#Acknowledgements:- Kattis.com for giving inspiration to this project.
#                 - http://stackoverflow.com/questions/4915920/ for lines 37-38
########################################################################################################################

'''
========================================================================================================================
PROBLEM STATEMENT:

Mrs. Chambers always has her class line up in height order (shortest at the front of the line).
Every September a new class of exactly 20 3rd graders arrive, all of different height.
For the first few days it takes a long time to get the kids in height order, since no one
knows where they should be in the line. Needless to say, there is quite a bit of jockeying
around. This year Mrs. Chambers decided to try a new method to minimize this ordering chaos.

One student would be selected to be the first person in line. Then, another student is selected
and would find the first person in the line that is taller than him, and stand in front of that
person, thereby causing all the students behind him to step back to make room. If there is no
student that is taller, then he would stand at the end of the line. This process continues,
one student at-a-time, until all the students are in line, at which point the students will
be lined up in height order.

For this problem, you will write a program that calculates the total number of steps taken
back during the ordering process for a given class of students.

========================================================================================================================
'''


import random
import copy

def main():
    for i in range(20):
        #Creation of word list.
        #Consist of 20 items along representative of height. consisting of heights of 20 students.
        #There are 20 sets of this data randomly generated.
        kid_list=[]
        for i in range(20):
            x=random.randrange(0,50)
            kid_list.append(x)

        kid_list2=copy.deepcopy(kid_list)
        ordered_list=[]

        def tallest(tallest_kid,height):
            '''
            Returns the tallest kid between 2 compared heights
            :param tallest_kid: Integer that represents greatest value in list of kids
            :param height: Integer that represents the compared value to the tallest kid
            :return:Integer that is the greatest value between the previous tallest kid and the current height
            '''

            if tallest_kid>=height:
                return tallest_kid
            else:
                return height


        def find_tallest_kid(kid_list,height):
            '''
            Returns the tallest kid of the group of kids
            :param kid_list:List of all heights
            :param height: List of only one height that changed based on the iteration of hte kid_list
            :return:Integer of the greatest value(tallest kid)
            '''
            tallest_kid=0
            for i in range(len(kid_list)):
                height=kid_list[i]
                tallest_kid=tallest(tallest_kid,height)
            i=kid_list.index(tallest_kid)
            del kid_list[i]
            return tallest_kid

        #Prints the list of heights
        print "Your heights are:\n",kid_list

        #Finds the tallest kid and appends them to an ordered list of heights.
        for i in range(len(kid_list)):
            tallest_kid=find_tallest_kid(kid_list,kid_list2[i])
            ordered_list.append(tallest_kid)
        ordered_list.reverse()

        print "Your ordered heights are:\n",ordered_list,"\n"*2

main()