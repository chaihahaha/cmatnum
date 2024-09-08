#include "fAx2944.h"

inline int fAx2944(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2944.data[i][j] = bmats.A_2_1.data[i][j] + bmats.A_2_11.data[i][j] + bmats.A_2_12.data[i][j] + bmats.A_2_13.data[i][j] + bmats.A_2_14.data[i][j] + bmats.A_2_15.data[i][j] + bmats.A_2_16.data[i][j] + bmats.A_2_2.data[i][j] + bmats.A_2_3.data[i][j] + bmats.A_2_4.data[i][j] + bmats.A_2_5.data[i][j] + bmats.A_2_6.data[i][j] + bmats.A_2_7.data[i][j] + bmats.A_2_8.data[i][j];
        }
    }
    return 0;
}
