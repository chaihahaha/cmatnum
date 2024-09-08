#include "fAx3290.h"

inline int fAx3290(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3290.data[i][j] = -11*bmats.A_12_19.data[i][j] + bmats.A_12_20.data[i][j] - 11*bmats.A_13_19.data[i][j] + bmats.A_13_20.data[i][j] - 11*bmats.A_14_19.data[i][j] + bmats.A_14_20.data[i][j] - 11*bmats.A_17_19.data[i][j] + bmats.A_17_20.data[i][j] - 11*bmats.A_18_19.data[i][j] + bmats.A_18_20.data[i][j] - 12*bmats.A_19_19.data[i][j] - 11*bmats.A_20_19.data[i][j] + bmats.A_20_20.data[i][j] - 11*bmats.A_21_19.data[i][j] + bmats.A_21_20.data[i][j] - 11*bmats.A_22_19.data[i][j] + bmats.A_22_20.data[i][j] + bmats.Ax1487.data[i][j] + bmats.Ax1676.data[i][j] + bmats.Ax1750.data[i][j] + bmats.Ax3140.data[i][j] + bmats.Ax3142.data[i][j] + bmats.Ax3144.data[i][j] + bmats.Ax3146.data[i][j] + bmats.Ax387.data[i][j];
        }
    }
    return 0;
}
