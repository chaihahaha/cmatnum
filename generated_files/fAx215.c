#include "fAx215.h"

inline int fAx215(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax215.data[i][j] = bmats.A_12_17.data[i][j] - 11*bmats.A_12_18.data[i][j] + bmats.A_15_17.data[i][j] - 11*bmats.A_15_18.data[i][j] + bmats.A_16_17.data[i][j] - 11*bmats.A_16_18.data[i][j] + bmats.A_17_17.data[i][j] - 11*bmats.A_17_18.data[i][j] - 12*bmats.A_18_18.data[i][j] + bmats.A_19_17.data[i][j] - 11*bmats.A_19_18.data[i][j] + bmats.A_20_17.data[i][j] - 11*bmats.A_20_18.data[i][j] + bmats.A_21_17.data[i][j] - 11*bmats.A_21_18.data[i][j] + bmats.A_22_17.data[i][j] - 11*bmats.A_22_18.data[i][j] + bmats.Ax49.data[i][j] + bmats.Ax52.data[i][j] + bmats.Ax55.data[i][j] + bmats.Ax58.data[i][j] + bmats.Ax64.data[i][j] + bmats.Ax67.data[i][j] + bmats.Ax70.data[i][j] + bmats.Ax73.data[i][j];
        }
    }
    return 0;
}
