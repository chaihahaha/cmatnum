#include "fAx998.h"

inline int fAx998(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax998.data[i][j] = -11*bmats.A_10_6.data[i][j] + bmats.A_10_7.data[i][j] - 11*bmats.A_11_6.data[i][j] + bmats.A_11_7.data[i][j] - 11*bmats.A_1_6.data[i][j] + bmats.A_1_7.data[i][j] - 11*bmats.A_4_6.data[i][j] + bmats.A_4_7.data[i][j] - 11*bmats.A_5_6.data[i][j] + bmats.A_5_7.data[i][j] - 12*bmats.A_6_6.data[i][j] - 11*bmats.A_7_6.data[i][j] + bmats.A_7_7.data[i][j] - 11*bmats.A_8_6.data[i][j] + bmats.A_8_7.data[i][j] - 11*bmats.A_9_6.data[i][j] + bmats.A_9_7.data[i][j] + bmats.Ax12.data[i][j] + bmats.Ax15.data[i][j] + bmats.Ax18.data[i][j] + bmats.Ax24.data[i][j] + bmats.Ax27.data[i][j] + bmats.Ax33.data[i][j] + bmats.Ax6.data[i][j] + bmats.Ax9.data[i][j];
        }
    }
    return 0;
}
