# Testcase
People data: 
id: 1 - John - NewYork
id: 2 - Alice - LosAngeles
id: 3 - Bob - Chicago
id: 4 - Diana - Houston
id: 5 - Eve - Phoenix
id: 6 - Frank - LosAngeles
id: 7 - Grace - NewYork
id: 1 - John - NewYork
id: 9 - Bob - Chicago
id: 10 - Leo - Chicago
id: 11 - Karen - Phoenix
id: 12 - Ivy - SanDiego
id: 13 - Mia - FortWorth
id: 14 - Diana - Houston
id: 15 - Oscar - Charlotte

Stack elements:
John - id: 1
Grace - id: 7
John - id: 1

Bucket 0: -> 15-Oscar -> 10-Leo -> 5-Eve 
Bucket 1: -> 11-Karen -> 6-Frank -> 1-John 
Bucket 2: -> 12-Ivy -> 7-Grace -> 2-Alice 
Bucket 3: -> 13-Mia -> 8-John -> 3-Bob 
Bucket 4: -> 14-Diana -> 9-Bob -> 4-Diana 

names: John Grace John 

QUEUE ELEMENTS:
1: John
7: Grace