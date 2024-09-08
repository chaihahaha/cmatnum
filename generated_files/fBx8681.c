#include "fBx8681.h"

inline int fBx8681(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx8681.data[i][j] = bmats.B_10_18.data[i][j] + bmats.B_10_19.data[i][j] + bmats.B_10_20.data[i][j] + bmats.B_10_21.data[i][j] + bmats.B_10_22.data[i][j] + bmats.B_10_23.data[i][j] + bmats.Bx7712.data[i][j];
        }
    }
    return 0;
}
