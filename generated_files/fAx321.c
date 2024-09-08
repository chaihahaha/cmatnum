#include "fAx321.h"

inline int fAx321(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax321.data[i][j] = bmats.A_17_17.data[i][j] + bmats.A_17_18.data[i][j] + bmats.A_17_19.data[i][j] + bmats.A_17_20.data[i][j] + bmats.A_17_21.data[i][j] + bmats.A_17_22.data[i][j] + bmats.A_17_25.data[i][j] + bmats.A_17_26.data[i][j] + bmats.A_17_27.data[i][j] + bmats.A_17_28.data[i][j] + bmats.A_17_29.data[i][j] + bmats.A_17_30.data[i][j] + bmats.A_17_31.data[i][j] + bmats.A_17_32.data[i][j];
        }
    }
    return 0;
}
