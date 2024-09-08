#include "fAx728.h"

inline int fAx728(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax728.data[i][j] = -11*bmats.A_12_17.data[i][j] + bmats.A_12_18.data[i][j] - 11*bmats.A_13_17.data[i][j] + bmats.A_13_18.data[i][j] - 11*bmats.A_14_17.data[i][j] + bmats.A_14_18.data[i][j] - 12*bmats.A_17_17.data[i][j] - 11*bmats.A_18_17.data[i][j] + bmats.A_18_18.data[i][j] - 11*bmats.A_19_17.data[i][j] + bmats.A_19_18.data[i][j] - 11*bmats.A_20_17.data[i][j] + bmats.A_20_18.data[i][j] - 11*bmats.A_21_17.data[i][j] + bmats.A_21_18.data[i][j] - 11*bmats.A_22_17.data[i][j] + bmats.A_22_18.data[i][j] + bmats.Ax46.data[i][j] + bmats.Ax49.data[i][j] + bmats.Ax52.data[i][j] + bmats.Ax55.data[i][j] + bmats.Ax58.data[i][j] + bmats.Ax61.data[i][j] + bmats.Ax73.data[i][j] + bmats.Ax76.data[i][j];
        }
    }
    return 0;
}
