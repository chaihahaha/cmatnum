#include "fAx319.h"

inline int fAx319(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax319.data[i][j] = -bmats.A_18_1.data[i][j] - bmats.A_18_10.data[i][j] - bmats.A_18_11.data[i][j] - bmats.A_18_2.data[i][j] - bmats.A_18_4.data[i][j] - bmats.A_18_5.data[i][j] - bmats.A_18_6.data[i][j] - bmats.A_18_7.data[i][j] - bmats.A_18_8.data[i][j] - bmats.A_18_9.data[i][j];
        }
    }
    return 0;
}
