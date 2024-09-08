#include "fAx706.h"

inline int fAx706(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax706.data[i][j] = bmats.A_19_1.data[i][j] + bmats.A_19_10.data[i][j] + bmats.A_19_11.data[i][j] + bmats.A_19_12.data[i][j] + bmats.A_19_13.data[i][j] + bmats.A_19_14.data[i][j] + bmats.A_19_2.data[i][j] + bmats.A_19_3.data[i][j] + bmats.A_19_4.data[i][j] + bmats.A_19_5.data[i][j] + bmats.A_19_6.data[i][j] + bmats.A_19_7.data[i][j] + bmats.A_19_8.data[i][j] + bmats.A_19_9.data[i][j];
        }
    }
    return 0;
}
