# **Automatic Report System**
This program is a help for the teacher to analyse and writing reports for students. It requieres a data input file with information of the students. Exam results, class tests, homework, etc.
## We need to create an input data file with the following fields:
HEADER line 1: Form X/AS/A2 winter reports 2023-2024\
HEADER line 2: [group] [surname] [name]	[sex]	[List of exam topics names that will appear in report to revise]	[mark]	[grade]	[predicted] [List of class test topics names] [List of formal homework]\
[Surname, name] [sex (F/M)] [Exam percentages by topic: motion, forces, hooke law, moments, density,...] [mark %] [grade] [predicted: yes or no] [Class test % per topic] [Formal homework % per topic]
## It is possible that we need to adapt the program according to the exam topics.
## Compilation
g++ [code name.cpp]
## How to run the code:
./a.out [data file to analyse.dat] > report.txt
