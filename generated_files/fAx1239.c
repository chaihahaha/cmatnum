#include "fAx1239.h"

inline int fAx1239(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1239.data[i][j] = -11*bmats.A_12_4.data[i][j] + bmats.A_12_5.data[i][j] - 11*bmats.A_13_4.data[i][j] + bmats.A_13_5.data[i][j] - 11*bmats.A_14_4.data[i][j] + bmats.A_14_5.data[i][j] - 11*bmats.A_15_4.data[i][j] + bmats.A_15_5.data[i][j] - 11*bmats.A_16_4.data[i][j] + bmats.A_16_5.data[i][j] - 11*bmats.A_17_4.data[i][j] + bmats.A_17_5.data[i][j] - 11*bmats.A_18_4.data[i][j] + bmats.A_18_5.data[i][j] - 11*bmats.A_19_4.data[i][j] + bmats.A_19_5.data[i][j] - 11*bmats.A_20_4.data[i][j] + bmats.A_20_5.data[i][j] - 11*bmats.A_21_4.data[i][j] + bmats.A_21_5.data[i][j] - 11*bmats.A_22_4.data[i][j] + bmats.A_22_5.data[i][j] + bmats.Ax730.data[i][j] + bmats.Ax920.data[i][j] + bmats.Ax923.data[i][j] + bmats.Ax926.data[i][j] + bmats.Ax929.data[i][j] + bmats.Ax932.data[i][j] + bmats.Ax935.data[i][j] + bmats.Ax938.data[i][j] + bmats.Ax941.data[i][j] + bmats.Ax944.data[i][j] + bmats.Ax947.data[i][j];
        }
    }
    return 0;
}
