#include "fAx2248.h"

inline int fAx2248(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2248.data[i][j] = bmats.A_27_1.data[i][j] + bmats.A_27_10.data[i][j] + bmats.A_27_13.data[i][j] + bmats.A_27_14.data[i][j] + bmats.A_27_15.data[i][j] + bmats.A_27_16.data[i][j] + bmats.A_27_2.data[i][j] + bmats.A_27_3.data[i][j] + bmats.A_27_4.data[i][j] + bmats.A_27_5.data[i][j] + bmats.A_27_6.data[i][j] + bmats.A_27_7.data[i][j] + bmats.A_27_8.data[i][j] + bmats.A_27_9.data[i][j];
        }
    }
    return 0;
}
