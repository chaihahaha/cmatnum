#include "fAx3087.h"

inline int fAx3087(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3087.data[i][j] = -11*bmats.A_12_10.data[i][j] + bmats.A_12_11.data[i][j] - 11*bmats.A_13_10.data[i][j] + bmats.A_13_11.data[i][j] - 11*bmats.A_14_10.data[i][j] + bmats.A_14_11.data[i][j] - 11*bmats.A_15_10.data[i][j] + bmats.A_15_11.data[i][j] - 11*bmats.A_16_10.data[i][j] + bmats.A_16_11.data[i][j] - 11*bmats.A_17_10.data[i][j] + bmats.A_17_11.data[i][j] - 11*bmats.A_18_10.data[i][j] + bmats.A_18_11.data[i][j] - 11*bmats.A_19_10.data[i][j] + bmats.A_19_11.data[i][j] - 11*bmats.A_20_10.data[i][j] + bmats.A_20_11.data[i][j] - 11*bmats.A_21_10.data[i][j] + bmats.A_21_11.data[i][j] - 11*bmats.A_22_10.data[i][j] + bmats.A_22_11.data[i][j] + bmats.Ax225.data[i][j] + bmats.Ax279.data[i][j] + bmats.Ax359.data[i][j] + bmats.Ax42.data[i][j] + bmats.Ax503.data[i][j] + bmats.Ax511.data[i][j] + bmats.Ax567.data[i][j] + bmats.Ax639.data[i][j] + bmats.Ax663.data[i][j] + bmats.Ax738.data[i][j] + bmats.Ax791.data[i][j];
        }
    }
    return 0;
}
