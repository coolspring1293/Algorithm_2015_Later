//
//  main.cpp
//  E - Brainwashing Device
//
//  Created by Kieran Will on 11/30/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//
//  http://acm.timus.ru/problem.aspx?space=1&num=1900

#include <iostream>



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
/*
 1900. Brainwashing Device
 Time limit: 1.0 second
 Memory limit: 64 MB
 While some people travel in space from planet to planet and discover new worlds, the others who live on Earth still have to get up in the morning, go to work, return back home and try to have a rest. They don't like this situation anymore and envy people who can afford space travel.
 That doesn't suit the government of the Earth. Their goal is to make everyone happy, but that is difficult. That is why the government decided to do some tests in the small town of Lux, and then, if everything goes well, to apply the experience to other cities.
 Lux's distinctive feature is that it is situated in a long underground tunnel and there is only one train inside it. Almost everyone in the town uses the train. The government has bought a brainwashing device and installed it in the train. The device is new and its effects aren't well understood yet, so the government decided to limit the number of the spans where the device would be turned on. Statistics on number of passengers travelling between each pair of stations every morning have already been collected. Now the government should pick the spans where the device could be used to make most of the people happy.
 Input
 The first line contains integers n and k that are the total number of the stations and the number of spans between adjacent stations where the device could be turned on (2 ≤ n ≤ 500; 1 ≤ k ≤ n − 1). The i'th of the next n − 1 lines contains n − i integers. The j'th integer is the number of passengers traveling from i'th to (i + j)'th station. These numbers are non-negative and don't exceed 100. You can assume that every passenger uses the train only once a day.
 Output
 In the first line output the total number of people who will become happy because of the device. In the second line output k integers in the ascending order that are the indexes of the spans where the device should be turned on. The span between the station i and i + 1 has the index i. If the problem has multiple solutions you can output any of them.
 Sample
 input
 4 1
 5 0 6
 5 3
 5
 output
 14
 3
 Problem Author: Alex Samsonov (prepared by Alexander Fetisov)
 Problem Source: Ural Championship 2012
 Tags: dynamic programming  (hide tags for unsolved problems)
 Difficulty: 446    Printable version    Submit solution    Discussion (7)
 All submissions (2879)    All accepted submissions (538)    Solutions rating (301)*/