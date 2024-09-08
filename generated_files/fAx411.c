#include "fAx411.h"

inline int fAx411(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax411.data[i][j] = -11*bmats.A_12_6.data[i][j] + bmats.A_12_7.data[i][j] - 11*bmats.A_13_6.data[i][j] + bmats.A_13_7.data[i][j] - 11*bmats.A_14_6.data[i][j] + bmats.A_14_7.data[i][j] - 11*bmats.A_15_6.data[i][j] + bmats.A_15_7.data[i][j] - 11*bmats.A_16_6.data[i][j] + bmats.A_16_7.data[i][j] - 11*bmats.A_17_6.data[i][j] + bmats.A_17_7.data[i][j] - 11*bmats.A_18_6.data[i][j] + bmats.A_18_7.data[i][j] - 11*bmats.A_19_6.data[i][j] + bmats.A_19_7.data[i][j] - 11*bmats.A_20_6.data[i][j] + bmats.A_20_7.data[i][j] - 11*bmats.A_21_6.data[i][j] + bmats.A_21_7.data[i][j] - 11*bmats.A_22_6.data[i][j] + bmats.A_22_7.data[i][j] + bmats.Ax101.data[i][j] + bmats.Ax104.data[i][j] + bmats.Ax107.data[i][j] + bmats.Ax110.data[i][j] + bmats.Ax113.data[i][j] + bmats.Ax83.data[i][j] + bmats.Ax86.data[i][j] + bmats.Ax89.data[i][j] + bmats.Ax92.data[i][j] + bmats.Ax95.data[i][j] + bmats.Ax98.data[i][j];
        }
    }
    return 0;
}
