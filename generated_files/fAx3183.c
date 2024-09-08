#include "fAx3183.h"

inline int fAx3183(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3183.data[i][j] = bmats.A_12_21.data[i][j] - 11*bmats.A_12_22.data[i][j] + bmats.A_13_21.data[i][j] - 11*bmats.A_13_22.data[i][j] + bmats.A_14_21.data[i][j] - 11*bmats.A_14_22.data[i][j] + bmats.A_15_21.data[i][j] - 11*bmats.A_15_22.data[i][j] + bmats.A_16_21.data[i][j] - 11*bmats.A_16_22.data[i][j] + bmats.A_19_21.data[i][j] - 11*bmats.A_19_22.data[i][j] + bmats.A_20_21.data[i][j] - 11*bmats.A_20_22.data[i][j] + bmats.A_21_21.data[i][j] - 11*bmats.A_21_22.data[i][j] - 12*bmats.A_22_22.data[i][j] + bmats.Ax193.data[i][j] + bmats.Ax265.data[i][j] + bmats.Ax316.data[i][j] + bmats.Ax479.data[i][j] + bmats.Ax551.data[i][j] + bmats.Ax699.data[i][j] + bmats.Ax776.data[i][j] + bmats.Ax828.data[i][j];
        }
    }
    return 0;
}
