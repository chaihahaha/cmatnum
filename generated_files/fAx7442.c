#include "fAx7442.h"

inline int fAx7442(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax7442.data[i][j] = -bmats.A_28_17.data[i][j] - bmats.A_28_18.data[i][j] - bmats.A_28_20.data[i][j] - bmats.A_28_21.data[i][j] - bmats.A_28_22.data[i][j] - bmats.A_28_23.data[i][j] - bmats.A_28_24.data[i][j] - bmats.A_28_25.data[i][j] - bmats.A_28_26.data[i][j] - bmats.A_28_27.data[i][j] - bmats.A_28_29.data[i][j] - bmats.A_28_31.data[i][j];
        }
    }
    return 0;
}