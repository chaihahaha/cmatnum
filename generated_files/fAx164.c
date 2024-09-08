#include "fAx164.h"

inline int fAx164(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax164.data[i][j] = bmats.A_10_17.data[i][j] - 11*bmats.A_10_18.data[i][j] + bmats.A_11_17.data[i][j] - 11*bmats.A_11_18.data[i][j] + bmats.A_1_17.data[i][j] - 11*bmats.A_1_18.data[i][j] + bmats.A_2_17.data[i][j] - 11*bmats.A_2_18.data[i][j] + bmats.A_3_17.data[i][j] - 11*bmats.A_3_18.data[i][j] + bmats.A_4_17.data[i][j] - 11*bmats.A_4_18.data[i][j] + bmats.A_5_17.data[i][j] - 11*bmats.A_5_18.data[i][j] + bmats.A_6_17.data[i][j] - 11*bmats.A_6_18.data[i][j] + bmats.A_7_17.data[i][j] - 11*bmats.A_7_18.data[i][j] + bmats.A_8_17.data[i][j] - 11*bmats.A_8_18.data[i][j] + bmats.A_9_17.data[i][j] - 11*bmats.A_9_18.data[i][j] + bmats.Ax132.data[i][j] + bmats.Ax135.data[i][j] + bmats.Ax138.data[i][j] + bmats.Ax141.data[i][j] + bmats.Ax144.data[i][j] + bmats.Ax147.data[i][j] + bmats.Ax150.data[i][j] + bmats.Ax153.data[i][j] + bmats.Ax156.data[i][j] + bmats.Ax159.data[i][j] + bmats.Ax162.data[i][j];
        }
    }
    return 0;
}
