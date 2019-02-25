#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 // the following code will MLE(memory limit exceeded) for very big data size
 // for example, when N = 1000000000, so should implement hashtable.
 // but to tedious to implement that using C, I think it is better to just use C++. =(
 // there is another C++ solution using hash table in the same directory of this file
 // feel free to take a look =)
int* gridIllumination(int N, int (*lamps)[2], int lampsRowSize, int (*queries)[2], int queriesRowSize, int* returnSize) {
    // store luminated lamp at r * N + c
    // from 0 to N*N-1
    bool **lamp = calloc(N, sizeof(bool*));
    for (int i = 0; i < N; ++i) {
        lamp[i] = calloc(N, sizeof(bool));
    }
    // store info of luminated lamp at r
    // from 0 to N-1
    short *row = calloc(N, sizeof(short));
    // store info of luminated lamp at c
    // from 0 to N-1
    short *col = calloc(N, sizeof(short));
    // store info of luminated lamp at r+c
    // from 0 to 2N-2
    short *diagonal1 = calloc((2 * N - 1), sizeof(short));
    // store info of luminated lamp at r-c
    // from 1-N to N-1, shift to positive -> from 0 to 2N-2
    short *diagonal2 = calloc((2 * N - 1), sizeof(short));
    int r, c;
    for (int i = 0; i < lampsRowSize; ++i) {
        r = lamps[i][0];
        c = lamps[i][1];
        ++row[r];
        ++col[c];
        ++diagonal1[r + c];
        ++diagonal2[r - c + N - 1];
        lamp[r][c] = true;
    }
    *returnSize = 0;
    int *result = malloc(queriesRowSize * sizeof(int));
    for (int i = 0; i < queriesRowSize; ++i) {
        r = queries[i][0];
        c = queries[i][1];
        if (row[r] || col[c] || diagonal1[r + c] || diagonal2[r - c + N - 1]) {
            result[(*returnSize)++] = 1;
            for (int y = r - 1; y <= r + 1; ++y) {
                for (int x = c - 1; x <= c + 1; ++x) {
                    // found a luminated lamp around r,c, turn it off
                    if (y >= 0 && y < N && x >= 0 && x < N && lamp[y][x]) {
                        lamp[y][x] = false;
                        --row[y];
                        --col[x];
                        --diagonal1[y + x];
                        --diagonal2[y - x + N - 1];
                    }
                }
            }
        } else {
            result[(*returnSize)++] = 0;
        }
    }
    free(row);
    free(col);
    free(diagonal1);
    free(diagonal2);
    for (int i = 0; i < N; ++i) {
        free(lamp[i]);
    }
    free(lamp);
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc < 2) {
        fprintf(stderr, "Usage: ./test inputs...\n");
        exit(-1);
    }
    */
    int lamps[][2] = {{6510, 7021}, {1587, 9424}, {2061, 2073}, {6036, 6088}, {3082, 1665}, {2893, 9835}, {5817, 1883}, {3648, 8657}, {7069, 6578}, {5029, 8663}, {6224, 4420}, {7464, 5340}, {9503, 8835}, {9526, 1396}, {6076, 1397}, {3460, 8217}, {3499, 4692}, {5592, 8677}, {2117, 1983}, {1230, 2824}, {3608, 9959}, {3300, 7064}, {9124, 4115}, {7662, 972}, {1279, 9756}, {3427, 9041}, {9907, 7202}, {7998, 5925}, {7723, 4565}, {5726, 8095}, {2585, 4524}, {1062, 1653}, {9155, 8914}, {2429, 5043}, {8881, 1716}, {464, 4235}, {8673, 5284}, {5931, 6944}, {484, 2505}, {724, 7322}, {9454, 2445}, {128, 2437}, {2969, 397}, {1068, 801}, {3602, 3517}, {661, 7187}, {251, 3986}, {480, 2051}, {7848, 7765}, {9779, 4653}, {1346, 7719}, {5466, 7584}, {7239, 7991}, {179, 5201}, {8647, 9470}, {1890, 9081}, {7529, 2884}, {78, 9347}, {4388, 7847}, {7282, 3151}, {5318, 1211}, {3101, 3410}, {1425, 5605}, {322, 5028}, {6729, 447}, {793, 3200}, {2023, 8872}, {3916, 295}, {3049, 7153}, {8251, 3805}, {4895, 3872}, {600, 9483}, {2176, 5153}, {1740, 3867}, {275, 9648}, {7792, 4384}, {3958, 4592}, {6517, 1003}, {4891, 7639}, {6157, 8614}, {1958, 7951}, {7791, 2910}, {8960, 1703}, {8823, 3105}, {3095, 688}, {7955, 4644}, {9676, 5121}, {1255, 9839}, {4867, 2692}, {2090, 7230}, {54, 710}, {8791, 9154}, {5347, 3355}, {6077, 2382}, {5081, 3911}, {5631, 9628}, {751, 3990}, {1285, 4709}, {2990, 8101}, {8825, 8860}, {2690, 5334}, {3307, 4404}, {9004, 4016}, {8030, 9717}, {5635, 941}, {6744, 1467}, {1294, 3355}, {2198, 7815}, {3739, 5308}, {7174, 8940}, {4652, 165}, {139, 4451}, {517, 8818}, {5516, 3880}, {4431, 7089}, {1285, 6810}, {9256, 5474}, {7508, 5903}, {5521, 4222}, {7357, 397}, {7086, 909}, {7175, 1250}, {4602, 4302}, {3613, 542}, {9664, 8691}, {718, 8436}, {7827, 6754}, {6622, 2253}, {4871, 517}, {915, 7444}, {9045, 9227}, {9000, 410}, {1787, 741}, {5373, 1652}, {1674, 8570}, {2405, 3192}, {3495, 7843}, {3366, 6676}, {6874, 6255}, {9949, 3623}, {3809, 1648}, {8903, 1814}, {2094, 1533}, {9065, 7448}, {2325, 3086}, {2938, 6379}, {64, 2099}, {4740, 8013}, {667, 6686}, {9510, 7715}, {4791, 996}, {4132, 3541}, {5403, 1743}, {4997, 8416}, {1822, 7119}, {8132, 5299}, {2783, 8580}, {4209, 242}, {9854, 2342}, {1277, 422}, {6816, 1134}, {5841, 75}, {2878, 7354}, {6647, 3313}, {4470, 8108}, {5887, 9500}, {457, 5644}, {5980, 3044}, {1515, 1922}, {5781, 8134}, {3831, 3949}, {5780, 2640}, {2248, 6126}, {5642, 7689}, {7073, 6061}, {1577, 5463}, {7398, 8611}, {3177, 4727}, {1185, 2479}, {964, 2872}, {9870, 4530}, {1321, 1200}, {5215, 3170}, {6492, 5910}, {5384, 2986}, {4741, 2774}, {9892, 3193}, {8477, 7201}, {9774, 8111}, {5924, 730}, {8665, 5203}, {4302, 57}, {6969, 863}, {6785, 540}, {4568, 6690}, {3720, 4321}, {130, 7645}, {3571, 4526}, {4761, 1543}, {3093, 7802}, {1953, 2169}, {725, 3408}, {165, 99}, {9981, 6275}, {6977, 9301}, {1022, 501}, {1525, 4071}, {8314, 7630}, {2968, 9361}, {9385, 3036}, {7155, 8707}, {3237, 7613}, {1410, 3215}, {4013, 5894}, {1559, 3642}, {8981, 9679}, {7575, 9567}, {6469, 6613}, {9690, 2139}, {3222, 9431}, {6735, 9202}, {1208, 4346}, {646, 3657}, {495, 421}, {6420, 6266}, {7537, 8037}, {7843, 7731}, {5289, 3946}, {7823, 5335}, {5256, 2121}, {3642, 2827}, {7406, 6440}, {6600, 8506}, {8981, 5972}, {6468, 6322}, {23, 2142}, {1770, 2245}, {3491, 7834}, {7098, 1785}, {7020, 3375}, {2460, 4904}, {2298, 5722}, {5894, 7089}, {9847, 7386}, {9303, 9221}, {610, 1333}, {7168, 1179}, {9952, 3778}, {8774, 9244}, {6918, 541}, {8370, 791}, {6224, 8999}, {8144, 398}, {4622, 2691}, {3811, 2136}, {4209, 4234}, {4576, 6413}, {8994, 152}, {3806, 5005}, {8332, 1677}, {7804, 9049}, {7885, 8732}, {5835, 8760}, {873, 8527}, {80, 2356}, {6311, 9777}, {1540, 2890}, {3106, 2818}, {9572, 6702}, {5369, 4551}, {6576, 4996}, {2847, 9000}, {9360, 4760}, {2539, 689}, {3258, 6151}, {4490, 8817}, {4286, 3908}, {1480, 3645}, {1195, 3956}, {7371, 6670}, {1142, 3458}, {9768, 2911}, {234, 1084}, {9723, 6704}, {7747, 1188}, {9252, 7190}, {8418, 8783}, {3813, 4248}, {6396, 3178}, {7413, 7811}, {3435, 7760}, {6575, 8792}, {251, 7349}, {7988, 1977}, {4974, 1070}, {6133, 1855}, {1529, 6263}, {7658, 5415}, {7029, 6204}, {8461, 7280}, {9839, 4592}, {8111, 2350}, {1896, 3161}, {9395, 1979}, {8069, 8433}, {6830, 9313}, {3664, 1655}, {2894, 1040}, {8997, 2316}, {7711, 4558}, {5958, 9879}, {3143, 2259}, {2136, 193}, {1179, 5065}, {2740, 9530}, {8, 5874}, {4150, 5170}, {7659, 401}, {9873, 2112}, {8697, 5103}, {4090, 6671}, {9944, 1336}, {7497, 4604}, {4980, 8316}, {187, 345}, {2203, 3838}, {4114, 6158}, {9761, 7816}, {1843, 4194}, {1181, 229}, {7639, 838}, {3162, 6278}, {3755, 587}, {7175, 7006}, {3968, 8342}, {6440, 6166}, {187, 1251}, {1362, 1258}, {9862, 1775}, {2003, 2281}, {9677, 6445}, {1255, 8665}, {9442, 3746}, {1220, 8368}, {5386, 6442}, {2495, 7900}, {9006, 9952}, {5269, 6125}, {6427, 7769}, {5524, 4902}, {5810, 3450}, {4142, 7343}, {7960, 7982}, {2461, 7157}, {3239, 3793}, {5241, 3641}, {3900, 1735}, {116, 9277}, {3751, 4166}, {8479, 9338}, {8046, 9687}, {6498, 3805}, {6874, 2281}, {7784, 1621}, {7528, 7966}, {9440, 9431}, {2713, 6589}, {3021, 4762}, {5394, 8446}, {6247, 108}, {2733, 2401}, {776, 4827}, {279, 9879}, {3424, 6892}, {6576, 5127}, {9746, 3191}, {9806, 2683}, {8741, 4008}, {3946, 3264}, {1107, 2768}, {4864, 9242}, {285, 8099}, {4948, 2397}, {1733, 9400}, {824, 6229}, {1986, 4796}, {6487, 9759}, {3920, 3327}, {9262, 3982}, {2093, 789}, {957, 8055}, {9965, 310}, {6602, 6533}, {360, 5374}, {9118, 8581}, {5463, 2222}, {6646, 6747}, {506, 489}, {6467, 3244}, {2308, 4168}, {6234, 866}, {5389, 6455}, {1637, 123}, {7631, 8485}, {3329, 6058}, {8266, 4712}, {1454, 5429}, {7953, 391}, {882, 9013}, {923, 9518}, {2310, 2057}, {5954, 4621}, {5879, 2419}, {8167, 729}, {4438, 4265}, {812, 3786}, {3321, 6021}, {6696, 9403}, {7912, 4614}, {9319, 4478}, {7440, 93}, {3064, 3365}, {2276, 1089}, {2573, 4458}, {8343, 587}, {4622, 2008}, {5107, 5515}, {9590, 8239}, {9589, 4529}, {6309, 5572}, {6094, 7828}, {8076, 4910}, {1027, 5535}, {388, 7435}, {4590, 8767}, {823, 6921}, {5692, 3174}, {7701, 4269}, {7805, 1835}, {9809, 399}, {855, 8536}, {354, 5148}, {1043, 7019}, {6611, 7475}, {9247, 6501}, {3634, 9913}, {5082, 7422}, {7700, 9605}, {3450, 8975}, {8880, 5508}, {8505, 6294}, {400, 1862}, {2660, 1078}, {483, 5407}, {4587, 7524}, {4798, 8279}, {564, 2219}, {2038, 3594}, {8617, 4585}, {2999, 105}, {1541, 2736}, {9200, 4536}, {8554, 1782}, {6197, 1598}, {3518, 1781}, {4188, 1704}, {5241, 9948}, {6704, 1781}, {7944, 6220}, {6242, 7435}, {3934, 4091}, {8322, 4049}, {2190, 916}, {122, 9939}, {3810, 9094}, {9444, 546}, {1287, 8049}, {6415, 6145}, {2462, 4124}, {4174, 8473}, {9469, 8881}, {888, 3045}, {2348, 8319}, {9481, 6407}, {2569, 3159}, {416, 6786}, {8164, 9664}, {527, 9389}, {7891, 9988}, {1679, 4278}, {8287, 624}, {3369, 7405}, {9318, 1112}, {8477, 5461}, {1575, 7136}, {3551, 2198}, {8073, 6244}, {4325, 8318}, {9940, 2577}, {6058, 8091}, {7670, 9194}, {1935, 4706}, {6815, 484}, {6373, 7516}, {6117, 6458}, {643, 1635}, {9297, 9129}, {2422, 5898}, {7745, 9653}, {5948, 962}, {4164, 7027}, {6664, 1910}, {1441, 6861}, {1346, 6528}, {9504, 4145}, {2372, 4065}, {6511, 8450}, {8605, 29}, {4958, 7765}, {5938, 1068}, {5859, 4454}, {8376, 1611}, {7671, 1409}, {2668, 4505}, {9400, 985}, {5515, 970}, {6277, 196}, {586, 5320}, {5029, 7244}, {879, 877}, {112, 304}, {5861, 9049}, {3876, 4577}, {8125, 8674}, {4881, 5845}, {3304, 5135}, {4350, 5320}, {2749, 973}, {2642, 3846}, {1049, 3402}, {6155, 914}, {8826, 3261}, {7291, 1123}, {7076, 9004}, {1157, 6689}, {2300, 1475}, {6629, 572}, {4031, 660}, {4805, 8390}, {8444, 818}, {3401, 7220}, {4358, 3317}, {5844, 1744}, {3523, 9081}, {5312, 8922}, {2703, 9710}, {3819, 9490}, {394, 2905}, {5748, 3184}, {8614, 418}, {7490, 1293}, {3242, 8165}, {3405, 3319}, {3057, 7105}, {5539, 5393}, {460, 2091}, {7941, 9680}, {9804, 5020}, {7639, 4175}, {6345, 4591}, {195, 7212}, {5662, 2596}, {9303, 9689}, {3514, 7216}, {9986, 5916}, {8832, 2043}, {7627, 9247}, {9096, 1280}, {4330, 8176}, {5612, 8320}, {4205, 1586}, {7740, 7823}, {7397, 3179}, {3018, 8886}, {8502, 4900}, {4415, 1615}, {7098, 4364}, {6468, 93}, {3039, 4869}, {4858, 545}, {6596, 6309}, {7106, 6022}, {7088, 967}, {4966, 1414}, {3339, 1352}, {6174, 6994}, {6019, 4026}, {7436, 4590}, {6425, 404}, {993, 8642}, {5441, 7055}, {7285, 4346}, {7734, 7499}, {7779, 5207}, {5123, 7384}, {7498, 5917}, {443, 8030}, {7581, 5539}, {7650, 5285}, {1844, 7429}, {1153, 941}, {5657, 5573}, {8502, 1976}, {3692, 2918}, {7586, 731}, {5072, 7840}, {5993, 1633}, {3547, 15}, {3893, 3463}, {2042, 3348}, {7796, 961}, {7850, 5698}, {7525, 1028}, {1392, 354}, {6335, 7354}, {7011, 1696}, {8155, 2609}, {5724, 2619}, {4453, 3468}, {6477, 1033}, {2686, 4400}, {7511, 5904}, {8957, 1305}, {2658, 6446}, {4137, 1106}, {8473, 8227}, {7329, 2368}, {7563, 626}, {9652, 6904}, {3196, 5924}};
    int queries[][2] = {{5369, 1253}, {17, 2868}, {1337, 5203}, {2664, 1107}, {7232, 54}, {3166, 1974}, {9647, 2612}, {3510, 6307}, {4477, 9623}, {2553, 2648}, {8225, 556}, {9361, 852}, {7930, 2774}, {2412, 6588}, {7911, 6699}, {1295, 6039}, {1519, 9702}, {4497, 6771}, {4123, 980}, {9339, 3214}, {23, 2199}, {5007, 7677}, {7125, 2566}, {1598, 4312}, {1593, 6011}, {8048, 6828}, {654, 8531}, {7680, 9816}, {3567, 7714}, {8846, 7248}, {7823, 7404}, {2747, 7437}, {9074, 2973}, {8672, 7739}, {1505, 2242}, {4679, 6010}, {6026, 5742}, {2960, 1294}, {1422, 5878}, {4670, 5487}, {2834, 853}, {3928, 9354}, {2318, 1593}, {7768, 4398}, {2193, 3124}, {9311, 639}, {5979, 3596}, {5727, 2486}, {881, 2043}, {6015, 1327}, {8988, 9039}, {1771, 8585}, {7546, 1803}, {6530, 8906}, {1628, 3557}, {4502, 6761}, {919, 9862}, {9599, 5298}, {1651, 3309}, {8409, 7910}, {8463, 5660}, {7649, 744}, {3370, 7673}, {8075, 8736}, {5452, 6623}, {5583, 6940}, {2091, 1562}, {920, 7946}, {2326, 5599}, {2100, 1232}, {5230, 6241}, {2023, 7157}, {2040, 45}, {6455, 3012}, {5452, 8223}, {6017, 6544}, {729, 6603}, {1779, 8235}, {9663, 6293}, {4048, 9373}, {4547, 1081}, {7967, 9380}, {1342, 356}, {1084, 686}, {3502, 4008}, {5078, 9072}, {7764, 1948}, {2175, 4339}, {2245, 8202}, {7616, 7937}, {5738, 4224}, {3874, 3308}, {1519, 2671}, {5653, 1576}, {9175, 6607}, {4157, 1484}, {6150, 8761}, {8560, 69}, {8998, 8491}, {3785, 2851}, {7091, 5928}, {4664, 9659}, {399, 9606}, {1968, 8771}, {911, 8718}, {5192, 8296}, {8219, 111}, {6315, 5867}, {8930, 6891}, {104, 3632}, {1284, 7368}, {9826, 3486}, {6470, 3376}, {1152, 3538}, {5714, 5761}, {5566, 8443}, {2564, 7886}, {1307, 975}, {334, 541}, {4713, 4533}, {8820, 4551}, {6593, 1113}, {5169, 4636}, {6828, 5964}, {8801, 940}, {1370, 2977}, {8085, 638}, {2479, 2353}, {5394, 7437}, {161, 8152}, {3553, 2709}, {6428, 5446}, {8225, 3243}, {6686, 7342}, {2097, 1939}, {6811, 9226}, {8598, 9559}, {3354, 8389}, {4891, 6727}, {1893, 6095}, {6156, 8947}, {3773, 6525}, {2730, 1603}, {2869, 6263}, {5322, 8880}, {6738, 6201}, {7334, 3368}, {9249, 6386}, {5914, 6509}, {5569, 967}, {9752, 3655}, {4469, 1329}, {549, 2798}, {2899, 3595}, {7385, 7136}, {9559, 7797}, {3539, 2465}, {5713, 5492}, {4435, 7670}, {3602, 2303}, {3982, 4121}, {6612, 899}, {3502, 1401}, {9503, 1}, {6319, 214}, {4644, 8027}, {2611, 9321}, {7862, 5322}, {4655, 2394}, {1772, 5755}, {5628, 904}, {9025, 7165}, {8071, 405}, {7700, 9588}, {4993, 887}, {2600, 7946}, {3327, 6793}, {9221, 4649}, {2491, 6567}, {2181, 8226}, {9553, 8998}, {1864, 4312}, {3715, 4441}, {6305, 8278}, {2022, 2493}, {4502, 9781}, {1843, 3278}, {9827, 5767}, {6327, 9632}, {5464, 3311}, {2099, 9831}, {3655, 1414}, {2844, 6287}, {9959, 9096}, {3884, 8069}, {2660, 4373}, {2831, 8699}, {1292, 7200}, {3447, 6344}, {9219, 83}, {585, 2726}, {6064, 890}, {4526, 3714}, {2430, 5571}, {8083, 5776}, {6540, 4116}, {5113, 6277}, {6029, 8613}, {4981, 3963}, {2217, 3442}, {8033, 4208}, {4346, 8602}, {8954, 4599}, {9424, 6771}, {1600, 5589}, {7470, 1027}, {5145, 9829}, {8266, 8280}, {7901, 1733}, {5185, 9522}, {6539, 4967}, {6688, 7044}, {355, 2817}, {9980, 3030}, {7451, 4749}, {363, 8357}, {75, 4442}, {2217, 3458}, {6352, 9209}, {7253, 1631}, {3356, 320}, {1953, 4102}, {8548, 5419}, {2821, 9441}, {1169, 9910}, {3916, 2194}, {6992, 1620}, {7381, 4701}, {8546, 4763}, {9635, 3145}, {892, 7206}, {4830, 9236}, {7000, 1825}, {6320, 8172}, {1555, 2465}, {1785, 1862}, {8173, 4362}, {7852, 6330}, {7724, 5782}, {351, 7845}};
    int returnSize;
    int *result = gridIllumination(10000, lamps, sizeof(lamps) / sizeof(lamps[0]), queries, sizeof(queries) / sizeof(queries[0]), &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}
