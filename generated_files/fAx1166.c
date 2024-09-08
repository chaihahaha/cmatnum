#include "fAx1166.h"

inline int fAx1166(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1166.data[i][j] = -11*bmats.A_10_15.data[i][j] + bmats.A_10_16.data[i][j] - 11*bmats.A_11_15.data[i][j] + bmats.A_11_16.data[i][j] - 11*bmats.A_1_15.data[i][j] + bmats.A_1_16.data[i][j] - 11*bmats.A_2_15.data[i][j] + bmats.A_2_16.data[i][j] - 11*bmats.A_3_15.data[i][j] + bmats.A_3_16.data[i][j] - 11*bmats.A_4_15.data[i][j] + bmats.A_4_16.data[i][j] - 11*bmats.A_5_15.data[i][j] + bmats.A_5_16.data[i][j] - 11*bmats.A_6_15.data[i][j] + bmats.A_6_16.data[i][j] - 11*bmats.A_7_15.data[i][j] + bmats.A_7_16.data[i][j] - 11*bmats.A_8_15.data[i][j] + bmats.A_8_16.data[i][j] - 11*bmats.A_9_15.data[i][j] + bmats.A_9_16.data[i][j] + bmats.Ax736.data[i][j] + bmats.Ax953.data[i][j] + bmats.Ax956.data[i][j] + bmats.Ax959.data[i][j] + bmats.Ax962.data[i][j] + bmats.Ax965.data[i][j] + bmats.Ax968.data[i][j] + bmats.Ax971.data[i][j] + bmats.Ax974.data[i][j] + bmats.Ax977.data[i][j] + bmats.Ax980.data[i][j];
        }
    }
    return 0;
}
