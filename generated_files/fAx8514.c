#include "fAx8514.h"

inline int fAx8514(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax8514.data[i][j] = bmats.A_12_15.data[i][j] - 16*bmats.A_12_16.data[i][j] + bmats.A_13_15.data[i][j] - 16*bmats.A_13_16.data[i][j] + bmats.A_14_15.data[i][j] - 16*bmats.A_14_16.data[i][j] + bmats.A_15_15.data[i][j] - 16*bmats.A_15_16.data[i][j] - 17*bmats.A_16_16.data[i][j] + bmats.A_1_15.data[i][j] - 16*bmats.A_1_16.data[i][j] + bmats.A_2_15.data[i][j] - 16*bmats.A_2_16.data[i][j] + bmats.A_3_15.data[i][j] - 16*bmats.A_3_16.data[i][j] + bmats.A_4_15.data[i][j] - 16*bmats.A_4_16.data[i][j] + bmats.A_5_15.data[i][j] - 16*bmats.A_5_16.data[i][j] + bmats.A_6_15.data[i][j] - 16*bmats.A_6_16.data[i][j] + bmats.A_7_15.data[i][j] - 16*bmats.A_7_16.data[i][j] + bmats.A_8_15.data[i][j] - 16*bmats.A_8_16.data[i][j] + bmats.A_9_15.data[i][j] - 16*bmats.A_9_16.data[i][j] + bmats.Ax392.data[i][j] + bmats.Ax556.data[i][j] + bmats.Ax565.data[i][j] + bmats.Ax568.data[i][j] + bmats.Ax573.data[i][j] + bmats.Ax576.data[i][j] + bmats.Ax579.data[i][j] + bmats.Ax585.data[i][j] + bmats.Ax588.data[i][j] + bmats.Ax591.data[i][j] + bmats.Ax594.data[i][j] + bmats.Ax649.data[i][j] + bmats.Ax652.data[i][j];
        }
    }
    return 0;
}
