#include "fBx12637.h"

inline int fBx12637(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12637.data[i][j] = bmats.B_3_17.data[i][j] + bmats.B_3_18.data[i][j] + bmats.B_3_19.data[i][j] + bmats.B_3_20.data[i][j] + bmats.B_3_21.data[i][j] + bmats.B_3_22.data[i][j] + bmats.B_3_23.data[i][j] + bmats.B_3_24.data[i][j] + bmats.B_3_25.data[i][j] + bmats.B_3_26.data[i][j] + bmats.B_3_27.data[i][j] + bmats.B_3_28.data[i][j] + bmats.B_3_29.data[i][j] + bmats.B_3_30.data[i][j] + bmats.B_3_31.data[i][j] + bmats.B_3_32.data[i][j];
        }
    }
    return 0;
}
