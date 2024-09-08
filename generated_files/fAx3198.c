#include "fAx3198.h"

inline int fAx3198(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3198.data[i][j] = bmats.A_10_10.data[i][j] - 11*bmats.A_10_11.data[i][j] - 12*bmats.A_11_11.data[i][j] + bmats.A_1_10.data[i][j] - 11*bmats.A_1_11.data[i][j] + bmats.A_2_10.data[i][j] - 11*bmats.A_2_11.data[i][j] + bmats.A_3_10.data[i][j] - 11*bmats.A_3_11.data[i][j] + bmats.A_6_10.data[i][j] - 11*bmats.A_6_11.data[i][j] + bmats.A_7_10.data[i][j] - 11*bmats.A_7_11.data[i][j] + bmats.A_8_10.data[i][j] - 11*bmats.A_8_11.data[i][j] + bmats.A_9_10.data[i][j] - 11*bmats.A_9_11.data[i][j] + bmats.Ax178.data[i][j] + bmats.Ax261.data[i][j] + bmats.Ax312.data[i][j] + bmats.Ax464.data[i][j] + bmats.Ax531.data[i][j] + bmats.Ax547.data[i][j] + bmats.Ax644.data[i][j] + bmats.Ax696.data[i][j];
        }
    }
    return 0;
}
