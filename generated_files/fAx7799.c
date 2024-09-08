#include "fAx7799.h"

inline int fAx7799(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax7799.data[i][j] = bmats.A_17_15.data[i][j] - 16*bmats.A_17_16.data[i][j] + bmats.A_18_15.data[i][j] - 16*bmats.A_18_16.data[i][j] + bmats.A_19_15.data[i][j] - 16*bmats.A_19_16.data[i][j] + bmats.A_20_15.data[i][j] - 16*bmats.A_20_16.data[i][j] + bmats.A_21_15.data[i][j] - 16*bmats.A_21_16.data[i][j] + bmats.A_22_15.data[i][j] - 16*bmats.A_22_16.data[i][j] + bmats.A_23_15.data[i][j] - 16*bmats.A_23_16.data[i][j] + bmats.A_24_15.data[i][j] - 16*bmats.A_24_16.data[i][j] + bmats.A_25_15.data[i][j] - 16*bmats.A_25_16.data[i][j] + bmats.A_26_15.data[i][j] - 16*bmats.A_26_16.data[i][j] + bmats.A_27_15.data[i][j] - 16*bmats.A_27_16.data[i][j] + bmats.A_28_15.data[i][j] - 16*bmats.A_28_16.data[i][j] + bmats.A_29_15.data[i][j] - 16*bmats.A_29_16.data[i][j] + bmats.A_30_15.data[i][j] - 16*bmats.A_30_16.data[i][j] + bmats.A_31_15.data[i][j] - 16*bmats.A_31_16.data[i][j] + bmats.A_32_15.data[i][j] - 16*bmats.A_32_16.data[i][j] + bmats.Ax660.data[i][j] + bmats.Ax676.data[i][j] + bmats.Ax679.data[i][j] + bmats.Ax682.data[i][j] + bmats.Ax685.data[i][j] + bmats.Ax688.data[i][j] + bmats.Ax691.data[i][j] + bmats.Ax694.data[i][j] + bmats.Ax697.data[i][j] + bmats.Ax700.data[i][j] + bmats.Ax703.data[i][j] + bmats.Ax706.data[i][j] + bmats.Ax709.data[i][j] + bmats.Ax712.data[i][j] + bmats.Ax715.data[i][j] + bmats.Ax720.data[i][j];
        }
    }
    return 0;
}
