//
//  Header.h
//  C - Minimal Coverage
//
//  Created by Kieran Will on 11/28/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#ifndef Header_h
#define Header_h

/*给M条线段，要求覆盖[0,m]，问能否覆盖，至少需要多少条线段。
 
 *用贪心的想法，假设当前位置在now，那么此时添加一条线段使得左端点<=now，右端点最远，这样是最划算的，，
 
 *下次继续添加这样一条线段，使得右端点最远，左端点<=上一条选的线段的右端点。
 
 *扫完所有线段，now的位置可以到达m，则有解，否则无解。
 */
#endif /* Header_h */
