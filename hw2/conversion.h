//
// Created by mvcibuntu on 15.11.2020.
//

#ifndef HW2_CONVERSION_H
#define HW2_CONVERSION_H

namespace conversion {

    template <typename T>
    struct TypeManipHelper {
        T makeT() {
            T t;
            return t;
        }
    };

    template<typename T, typename U>
    struct Conversion {
    private:
        using Small = char;
        using Big = struct { char chars[2]; };

    private:
        static Small Test(U);

        static Big Test(...);

    public:
        static constexpr bool exists = sizeof(Small) == \
                sizeof(Test(TypeManipHelper<T>().makeT()));
        static constexpr bool isSame = false;
    };

    template<typename T>
    struct Conversion<T, T> {
        static constexpr bool exists = true;
        static constexpr bool isSame = true;
    };

    template<bool boolLhs, bool boolRhs>
    struct AndNotExpr {
        static constexpr bool res = false;
    };

    template<>
    struct AndNotExpr</* boolLhs = */true, /* boolRhs = */false> {
        static constexpr bool res = true;
    };

    template<typename T, typename U>
    struct IsBase {
        static constexpr bool res = AndNotExpr<
            /* boolLhs = */conversion::Conversion<const U*, const T*>::exists,
            /* boolRhs = */conversion::Conversion<const U*, const T*>::isSame
        >::res;
    };

};

#endif //HW2_CONVERSION_H
