//
//  main.cpp
//  D
//
//  Created by Kieran Will on 9/29/15.
//  Copyright (c) 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string ss[100001];

int main(int argc, const char * argv[]) {
    int n;
    ss[1] = "1";
    ss[2] = "2";
    ss[3] = "12";
    ss[4] = "12";
    ss[5] = "Impossible";
    ss[6] = "12";
    ss[7] = "21";
    ss[8] = "112";
    ss[9] = "12222";
    ss[10] = "Impossible";
    ss[11] = "11";
    ss[12] = "12";
    ss[13] = "221";
    ss[14] = "112";
    ss[15] = "Impossible";
    ss[16] = "112";
    ss[17] = "221";
    ss[18] = "12222";
    ss[19] = "1121";
    ss[20] = "Impossible";
    ss[21] = "21";
    ss[22] = "22";
    ss[23] = "12121";
    ss[24] = "2112";
    ss[25] = "Impossible";
    ss[26] = "1222";
    ss[27] = "21222";
    ss[28] = "112";
    ss[29] = "12122";
    ss[30] = "Impossible";
    ss[31] = "11222";
    ss[32] = "2112";
    ss[33] = "1122";
    ss[34] = "1122";
    ss[35] = "Impossible";
    ss[36] = "22212";
    ss[37] = "111";
    ss[38] = "12122";
    ss[39] = "111111";
    ss[40] = "Impossible";
    ss[41] = "11111";
    ss[42] = "12222";
    ss[43] = "12212";
    ss[44] = "2112";
    ss[45] = "Impossible";
    ss[46] = "122222";
    ss[47] = "1222";
    ss[48] = "2112";
    ss[49] = "11221";
    ss[50] = "Impossible";
    ss[51] = "1122";
    ss[52] = "21112";
    ss[53] = "212";
    ss[54] = "21222";
    ss[55] = "Impossible";
    ss[56] = "112";
    ss[57] = "212211";
    ss[58] = "12122";
    ss[59] = "1121";
    ss[60] = "Impossible";
    ss[61] = "122";
    ss[62] = "11222";
    ss[63] = "12222";
    ss[64] = "2112";
    ss[65] = "Impossible";
    ss[66] = "1122";
    ss[67] = "2211";
    ss[68] = "111112";
    ss[69] = "222111";
    ss[70] = "Impossible";
    ss[71] = "12212";
    ss[72] = "122112";
    ss[73] = "212211";
    ss[74] = "222";
    ss[75] = "Impossible";
    ss[76] = "111112";
    ss[77] = "111111";
    ss[78] = "121212";
    ss[79] = "2212";
    ss[80] = "Impossible";
    ss[81] = "21222";
    ss[82] = "22222";
    ss[83] = "11122";
    ss[84] = "121212";
    ss[85] = "Impossible";
    ss[86] = "12212";
    ss[87] = "222111";
    ss[88] = "2112";
    ss[89] = "1121222";
    ss[90] = "Impossible";
    ss[91] = "21112";
    ss[92] = "1121112";
    ss[93] = "21111";
    ss[94] = "1222";
    ss[95] = "Impossible";
    ss[96] = "2112";
    ss[97] = "12222";
    ss[98] = "112112";
    ss[99] = "1122222222";
    ss[100] = "Impossible";
    ss[101] = "1111";
    ss[102] = "1122";
    ss[103] = "2112221";
    ss[104] = "21112";
    ss[105] = "Impossible";
    ss[106] = "212";
    ss[107] = "211111";
    ss[108] = "112212";
    ss[109] = "2111112";
    ss[110] = "Impossible";
    ss[111] = "111";
    ss[112] = "112";
    ss[113] = "11121121";
    ss[114] = "21121122";
    ss[115] = "Impossible";
    ss[116] = "21112";
    ss[117] = "121212";
    ss[118] = "21122";
    ss[119] = "221221";
    ss[120] = "Impossible";
    ss[121] = "121";
    ss[122] = "122";
    ss[123] = "21112212";
    ss[124] = "2221212";
    ss[125] = "Impossible";
    ss[126] = "12222";
    ss[127] = "1222121";
    ss[128] = "122112";
    ss[129] = "2212221";
    ss[130] = "Impossible";
    ss[131] = "21222";
    ss[132] = "2112";
    ss[133] = "22211";
    ss[134] = "11122";
    ss[135] = "Impossible";
    ss[136] = "111112";
    ss[137] = "11111111";
    ss[138] = "1121112";
    ss[139] = "1112";
    ss[140] = "Impossible";
    ss[141] = "1111221";
    ss[142] = "12212";
    ss[143] = "111111";
    ss[144] = "122112";
    ss[145] = "Impossible";
    ss[146] = "222212";
    ss[147] = "212121";
    ss[148] = "121212";
    ss[149] = "1211221";
    ss[150] = "Impossible";
    ss[151] = "222121";
    ss[152] = "111112";
    ss[153] = "212211";
    ss[154] = "112112";
    ss[155] = "Impossible";
    ss[156] = "121212";
    ss[157] = "2112121";
    ss[158] = "2212";
    ss[159] = "122112";
    ss[160] = "Impossible";
    ss[161] = "1111222";
    ss[162] = "21222";
    ss[163] = "11111221";
    ss[164] = "2211212";
    ss[165] = "Impossible";
    ss[166] = "11122";
    ss[167] = "22211";
    ss[168] = "1211112";
    ss[169] = "221221";
    ss[170] = "Impossible";
    ss[171] = "212211";
    ss[172] = "12212";
    ss[173] = "1211";
    ss[174] = "11212212";
    ss[175] = "Impossible";
    ss[176] = "2112";
    ss[177] = "1211211";
    ss[178] = "1121222";
    ss[179] = "21122";
    ss[180] = "Impossible";
    ss[181] = "11222";
    ss[182] = "21112";
    ss[183] = "11111211";
    ss[184] = "1121112";
    ss[185] = "Impossible";
    
    while (cin >> n) {
        cout << ss[n] << "\n";
    }
    return 0;
}
