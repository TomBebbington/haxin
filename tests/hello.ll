; ModuleID = 'tests/hello.cpp'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%"class.std::ios_base::Init" = type { i8 }
%"class.std::basic_ostream" = type { i32 (...)**, %"class.std::basic_ios" }
%"class.std::basic_ios" = type { %"class.std::ios_base", %"class.std::basic_ostream"*, i8, i8, %"class.std::basic_streambuf"*, %"class.std::ctype"*, %"class.std::num_put"*, %"class.std::num_get"* }
%"class.std::ios_base" = type { i32 (...)**, i64, i64, i32, i32, i32, %"struct.std::ios_base::_Callback_list"*, %"struct.std::ios_base::_Words", [8 x %"struct.std::ios_base::_Words"], i32, %"struct.std::ios_base::_Words"*, %"class.std::locale" }
%"struct.std::ios_base::_Callback_list" = type { %"struct.std::ios_base::_Callback_list"*, void (i32, %"class.std::ios_base"*, i32)*, i32, i32 }
%"struct.std::ios_base::_Words" = type { i8*, i64 }
%"class.std::locale" = type { %"class.std::locale::_Impl"* }
%"class.std::locale::_Impl" = type { i32, %"class.std::locale::facet"**, i64, %"class.std::locale::facet"**, i8** }
%"class.std::locale::facet" = type { i32 (...)**, i32 }
%"class.std::basic_streambuf" = type { i32 (...)**, i8*, i8*, i8*, i8*, i8*, i8*, %"class.std::locale" }
%"class.std::ctype" = type { %"class.std::locale::facet", %struct.__locale_struct*, i8, i32*, i32*, i16*, i8, [256 x i8], [256 x i8], i8 }
%struct.__locale_struct = type { [13 x %struct.__locale_data*], i16*, i32*, i32*, [13 x i8*] }
%struct.__locale_data = type opaque
%"class.std::num_put" = type { %"class.std::locale::facet" }
%"class.std::num_get" = type { %"class.std::locale::facet" }
%union.SDL_Event = type { %struct.SDL_UserEvent }
%struct.SDL_UserEvent = type { i8, i32, i8*, i8* }
%struct.SDL_Surface = type { i32, %struct.SDL_PixelFormat*, i32, i32, i16, i8*, i32, %struct.private_hwdata*, %struct.SDL_Rect, i32, i32, %struct.SDL_BlitMap*, i32, i32 }
%struct.SDL_PixelFormat = type { %struct.SDL_Palette*, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i32, i32, i32, i32, i32, i8 }
%struct.SDL_Palette = type { i32, %struct.SDL_Color* }
%struct.SDL_Color = type { i8, i8, i8, i8 }
%struct.private_hwdata = type opaque
%struct.SDL_Rect = type { i16, i16, i16, i16 }
%struct.SDL_BlitMap = type opaque

@_ZStL8__ioinit = internal global %"class.std::ios_base::Init" zeroinitializer, align 1
@__dso_handle = external global i8
@_ZSt4cout = external global %"class.std::basic_ostream"
@.str = private unnamed_addr constant [17 x i8] c"Failed SDL_Init \00", align 1
@.str1 = private unnamed_addr constant [26 x i8] c"Failed SDL_SetVideoMode: \00", align 1
@llvm.global_ctors = appending global [1 x { i32, void ()* }] [{ i32, void ()* } { i32 65535, void ()* @_GLOBAL__I_a }]

declare void @_ZNSt8ios_base4InitC1Ev(%"class.std::ios_base::Init"*) #0

declare void @_ZNSt8ios_base4InitD1Ev(%"class.std::ios_base::Init"*) #0

; Function Attrs: nounwind
declare i32 @__cxa_atexit(void (i8*)*, i8*, i8*) #1

; Function Attrs: uwtable
define i32 @main(i32 %argc, i8** nocapture %argv) #2 {
  %event = alloca %union.SDL_Event, align 8
  %1 = call i32 @SDL_Init(i32 32)
  %2 = icmp slt i32 %1, 0
  br i1 %2, label %3, label %44

; <label>:3                                       ; preds = %0
  %4 = call %"class.std::basic_ostream"* @_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l(%"class.std::basic_ostream"* @_ZSt4cout, i8* getelementptr inbounds ([17 x i8]* @.str, i64 0, i64 0), i64 16)
  %5 = call i8* @SDL_GetError()
  %6 = icmp eq i8* %5, null
  br i1 %6, label %7, label %18

; <label>:7                                       ; preds = %3
  %8 = load i8** bitcast (%"class.std::basic_ostream"* @_ZSt4cout to i8**), align 8, !tbaa !0
  %9 = getelementptr i8* %8, i64 -24
  %10 = bitcast i8* %9 to i64*
  %11 = load i64* %10, align 8
  %12 = getelementptr inbounds i8* bitcast (%"class.std::basic_ostream"* @_ZSt4cout to i8*), i64 %11
  %13 = bitcast i8* %12 to %"class.std::basic_ios"*
  %.sum.i = add i64 %11, 32
  %14 = getelementptr inbounds i8* bitcast (%"class.std::basic_ostream"* @_ZSt4cout to i8*), i64 %.sum.i
  %15 = bitcast i8* %14 to i32*
  %16 = load i32* %15, align 4, !tbaa !2
  %17 = or i32 %16, 1
  call void @_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate(%"class.std::basic_ios"* %13, i32 %17)
  br label %_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.exit

; <label>:18                                      ; preds = %3
  %19 = call i64 @strlen(i8* %5) #1
  %20 = call %"class.std::basic_ostream"* @_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l(%"class.std::basic_ostream"* @_ZSt4cout, i8* %5, i64 %19)
  br label %_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.exit

_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.exit: ; preds = %7, %18
  %21 = load i8** bitcast (%"class.std::basic_ostream"* @_ZSt4cout to i8**), align 8, !tbaa !0
  %22 = getelementptr i8* %21, i64 -24
  %23 = bitcast i8* %22 to i64*
  %24 = load i64* %23, align 8
  %.sum8 = add i64 %24, 240
  %25 = getelementptr inbounds i8* bitcast (%"class.std::basic_ostream"* @_ZSt4cout to i8*), i64 %.sum8
  %26 = bitcast i8* %25 to %"class.std::ctype"**
  %27 = load %"class.std::ctype"** %26, align 8, !tbaa !4
  %28 = icmp eq %"class.std::ctype"* %27, null
  br i1 %28, label %29, label %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit

; <label>:29                                      ; preds = %_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.exit
  call void @_ZSt16__throw_bad_castv() #6
  unreachable

_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit:    ; preds = %_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.exit
  %30 = getelementptr inbounds %"class.std::ctype"* %27, i64 0, i32 6
  %31 = load i8* %30, align 1, !tbaa !3
  %32 = icmp eq i8 %31, 0
  br i1 %32, label %36, label %33

; <label>:33                                      ; preds = %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit
  %34 = getelementptr inbounds %"class.std::ctype"* %27, i64 0, i32 7, i64 10
  %35 = load i8* %34, align 1, !tbaa !3
  br label %_ZNKSt5ctypeIcE5widenEc.exit

; <label>:36                                      ; preds = %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit
  call void @_ZNKSt5ctypeIcE13_M_widen_initEv(%"class.std::ctype"* %27)
  %37 = bitcast %"class.std::ctype"* %27 to i8 (%"class.std::ctype"*, i8)***
  %38 = load i8 (%"class.std::ctype"*, i8)*** %37, align 8, !tbaa !0
  %39 = getelementptr inbounds i8 (%"class.std::ctype"*, i8)** %38, i64 6
  %40 = load i8 (%"class.std::ctype"*, i8)** %39, align 8
  %41 = call signext i8 %40(%"class.std::ctype"* %27, i8 signext 10)
  br label %_ZNKSt5ctypeIcE5widenEc.exit

_ZNKSt5ctypeIcE5widenEc.exit:                     ; preds = %33, %36
  %.0.i = phi i8 [ %35, %33 ], [ %41, %36 ]
  %42 = call %"class.std::basic_ostream"* @_ZNSo3putEc(%"class.std::basic_ostream"* @_ZSt4cout, i8 signext %.0.i)
  %43 = call %"class.std::basic_ostream"* @_ZNSo5flushEv(%"class.std::basic_ostream"* %42)
  br label %.loopexit9

; <label>:44                                      ; preds = %0
  %45 = call %struct.SDL_Surface* @SDL_SetVideoMode(i32 800, i32 600, i32 32, i32 268435456)
  %46 = icmp eq %struct.SDL_Surface* %45, null
  br i1 %46, label %54, label %.preheader

.preheader:                                       ; preds = %44
  %47 = getelementptr inbounds %struct.SDL_Surface* %45, i64 0, i32 1
  %48 = getelementptr inbounds %struct.SDL_Surface* %45, i64 0, i32 5
  %49 = getelementptr inbounds %struct.SDL_Surface* %45, i64 0, i32 4
  %50 = getelementptr inbounds %struct.SDL_Surface* %45, i64 0, i32 2
  %51 = getelementptr inbounds %struct.SDL_Surface* %45, i64 0, i32 3
  %52 = getelementptr inbounds %union.SDL_Event* %event, i64 0, i32 0, i32 1
  %53 = getelementptr inbounds i32* %52, i64 1
  br label %95

; <label>:54                                      ; preds = %44
  %55 = call %"class.std::basic_ostream"* @_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l(%"class.std::basic_ostream"* @_ZSt4cout, i8* getelementptr inbounds ([26 x i8]* @.str1, i64 0, i64 0), i64 25)
  %56 = call i8* @SDL_GetError()
  %57 = icmp eq i8* %56, null
  br i1 %57, label %58, label %69

; <label>:58                                      ; preds = %54
  %59 = load i8** bitcast (%"class.std::basic_ostream"* @_ZSt4cout to i8**), align 8, !tbaa !0
  %60 = getelementptr i8* %59, i64 -24
  %61 = bitcast i8* %60 to i64*
  %62 = load i64* %61, align 8
  %63 = getelementptr inbounds i8* bitcast (%"class.std::basic_ostream"* @_ZSt4cout to i8*), i64 %62
  %64 = bitcast i8* %63 to %"class.std::basic_ios"*
  %.sum.i2 = add i64 %62, 32
  %65 = getelementptr inbounds i8* bitcast (%"class.std::basic_ostream"* @_ZSt4cout to i8*), i64 %.sum.i2
  %66 = bitcast i8* %65 to i32*
  %67 = load i32* %66, align 4, !tbaa !2
  %68 = or i32 %67, 1
  call void @_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate(%"class.std::basic_ios"* %64, i32 %68)
  br label %_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.exit3

; <label>:69                                      ; preds = %54
  %70 = call i64 @strlen(i8* %56) #1
  %71 = call %"class.std::basic_ostream"* @_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l(%"class.std::basic_ostream"* @_ZSt4cout, i8* %56, i64 %70)
  br label %_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.exit3

_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.exit3: ; preds = %58, %69
  %72 = load i8** bitcast (%"class.std::basic_ostream"* @_ZSt4cout to i8**), align 8, !tbaa !0
  %73 = getelementptr i8* %72, i64 -24
  %74 = bitcast i8* %73 to i64*
  %75 = load i64* %74, align 8
  %.sum7 = add i64 %75, 240
  %76 = getelementptr inbounds i8* bitcast (%"class.std::basic_ostream"* @_ZSt4cout to i8*), i64 %.sum7
  %77 = bitcast i8* %76 to %"class.std::ctype"**
  %78 = load %"class.std::ctype"** %77, align 8, !tbaa !4
  %79 = icmp eq %"class.std::ctype"* %78, null
  br i1 %79, label %80, label %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit6

; <label>:80                                      ; preds = %_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.exit3
  call void @_ZSt16__throw_bad_castv() #6
  unreachable

_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit6:   ; preds = %_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.exit3
  %81 = getelementptr inbounds %"class.std::ctype"* %78, i64 0, i32 6
  %82 = load i8* %81, align 1, !tbaa !3
  %83 = icmp eq i8 %82, 0
  br i1 %83, label %87, label %84

; <label>:84                                      ; preds = %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit6
  %85 = getelementptr inbounds %"class.std::ctype"* %78, i64 0, i32 7, i64 10
  %86 = load i8* %85, align 1, !tbaa !3
  br label %_ZNKSt5ctypeIcE5widenEc.exit5

; <label>:87                                      ; preds = %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit6
  call void @_ZNKSt5ctypeIcE13_M_widen_initEv(%"class.std::ctype"* %78)
  %88 = bitcast %"class.std::ctype"* %78 to i8 (%"class.std::ctype"*, i8)***
  %89 = load i8 (%"class.std::ctype"*, i8)*** %88, align 8, !tbaa !0
  %90 = getelementptr inbounds i8 (%"class.std::ctype"*, i8)** %89, i64 6
  %91 = load i8 (%"class.std::ctype"*, i8)** %90, align 8
  %92 = call signext i8 %91(%"class.std::ctype"* %78, i8 signext 10)
  br label %_ZNKSt5ctypeIcE5widenEc.exit5

_ZNKSt5ctypeIcE5widenEc.exit5:                    ; preds = %84, %87
  %.0.i4 = phi i8 [ %86, %84 ], [ %92, %87 ]
  %93 = call %"class.std::basic_ostream"* @_ZNSo3putEc(%"class.std::basic_ostream"* @_ZSt4cout, i8 signext %.0.i4)
  %94 = call %"class.std::basic_ostream"* @_ZNSo5flushEv(%"class.std::basic_ostream"* %93)
  call void @SDL_Quit()
  br label %.loopexit9

; <label>:95                                      ; preds = %.preheader, %._crit_edge
  %96 = call i32 @SDL_Flip(%struct.SDL_Surface* %45)
  %97 = call i32 @SDL_LockSurface(%struct.SDL_Surface* %45)
  br label %98

; <label>:98                                      ; preds = %95, %124
  %n.010 = phi i32 [ 0, %95 ], [ %126, %124 ]
  %99 = call i32 @rand() #1
  %100 = srem i32 %99, 800
  %101 = call i32 @rand() #1
  %102 = srem i32 %101, 600
  %103 = call i32 @rand() #1
  %104 = mul nsw i32 %103, 100000
  %105 = load %struct.SDL_PixelFormat** %47, align 8, !tbaa !4
  %106 = getelementptr inbounds %struct.SDL_PixelFormat* %105, i64 0, i32 2
  %107 = load i8* %106, align 1, !tbaa !3
  %108 = zext i8 %107 to i32
  %109 = load i8** %48, align 8, !tbaa !4
  %110 = load i16* %49, align 2, !tbaa !5
  %111 = zext i16 %110 to i32
  %112 = mul nsw i32 %111, %102
  %113 = sext i32 %112 to i64
  %114 = mul nsw i32 %108, %100
  %115 = sext i32 %114 to i64
  %.sum = add i64 %113, %115
  %116 = getelementptr inbounds i8* %109, i64 %.sum
  %117 = load i32* %50, align 4, !tbaa !6
  %118 = icmp sgt i32 %100, %117
  br i1 %118, label %.loopexit9, label %119

; <label>:119                                     ; preds = %98
  %120 = load i32* %51, align 4, !tbaa !6
  %121 = icmp sgt i32 %102, %120
  %122 = icmp slt i32 %100, 0
  %or.cond = or i1 %121, %122
  %123 = icmp slt i32 %102, 0
  %or.cond1 = or i1 %or.cond, %123
  br i1 %or.cond1, label %.loopexit9, label %124

; <label>:124                                     ; preds = %119
  %125 = bitcast i8* %116 to i32*
  store i32 %104, i32* %125, align 4, !tbaa !6
  %126 = add nsw i32 %n.010, 1
  %127 = icmp slt i32 %126, 1000
  br i1 %127, label %98, label %.loopexit

.loopexit:                                        ; preds = %124
  %128 = call i32 @SDL_PollEvent(%union.SDL_Event* %event)
  %129 = icmp eq i32 %128, 0
  br i1 %129, label %._crit_edge, label %.lr.ph

.lr.ph:                                           ; preds = %.loopexit, %.backedge
  %130 = load i32* %53, align 4, !tbaa !7
  %131 = icmp eq i32 %130, 99
  br i1 %131, label %132, label %.backedge

; <label>:132                                     ; preds = %.lr.ph
  %133 = call i32 @SDL_FillRect(%struct.SDL_Surface* %45, %struct.SDL_Rect* null, i32 0)
  br label %.backedge

.backedge:                                        ; preds = %132, %.lr.ph
  %134 = call i32 @SDL_PollEvent(%union.SDL_Event* %event)
  %135 = icmp eq i32 %134, 0
  br i1 %135, label %._crit_edge, label %.lr.ph

._crit_edge:                                      ; preds = %.backedge, %.loopexit
  call void @SDL_UnlockSurface(%struct.SDL_Surface* %45)
  br label %95

.loopexit9:                                       ; preds = %98, %119, %_ZNKSt5ctypeIcE5widenEc.exit5, %_ZNKSt5ctypeIcE5widenEc.exit
  %.0 = phi i32 [ 1, %_ZNKSt5ctypeIcE5widenEc.exit ], [ 1, %_ZNKSt5ctypeIcE5widenEc.exit5 ], [ 0, %119 ], [ 0, %98 ]
  ret i32 %.0
}

declare i32 @SDL_Init(i32) #0

declare i8* @SDL_GetError() #0

declare %struct.SDL_Surface* @SDL_SetVideoMode(i32, i32, i32, i32) #0

declare void @SDL_Quit() #0

declare i32 @SDL_Flip(%struct.SDL_Surface*) #0

declare i32 @SDL_LockSurface(%struct.SDL_Surface*) #0

; Function Attrs: nounwind
declare i32 @rand() #3

declare i32 @SDL_PollEvent(%union.SDL_Event*) #0

declare i32 @SDL_FillRect(%struct.SDL_Surface*, %struct.SDL_Rect*, i32) #0

declare void @SDL_UnlockSurface(%struct.SDL_Surface*) #0

declare %"class.std::basic_ostream"* @_ZNSo3putEc(%"class.std::basic_ostream"*, i8 signext) #0

declare void @_ZNKSt5ctypeIcE13_M_widen_initEv(%"class.std::ctype"*) #0

; Function Attrs: noreturn
declare void @_ZSt16__throw_bad_castv() #4

declare %"class.std::basic_ostream"* @_ZNSo5flushEv(%"class.std::basic_ostream"*) #0

declare %"class.std::basic_ostream"* @_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l(%"class.std::basic_ostream"*, i8*, i64) #0

; Function Attrs: nounwind readonly
declare i64 @strlen(i8* nocapture) #5

declare void @_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate(%"class.std::basic_ios"*, i32) #0

define internal void @_GLOBAL__I_a() section ".text.startup" {
  tail call void @_ZNSt8ios_base4InitC1Ev(%"class.std::ios_base::Init"* @_ZStL8__ioinit)
  %1 = tail call i32 @__cxa_atexit(void (i8*)* bitcast (void (%"class.std::ios_base::Init"*)* @_ZNSt8ios_base4InitD1Ev to void (i8*)*), i8* getelementptr inbounds (%"class.std::ios_base::Init"* @_ZStL8__ioinit, i64 0, i32 0), i8* @__dso_handle) #1
  ret void
}

attributes #0 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-frame-pointer-elim-non-leaf"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind }
attributes #2 = { uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-frame-pointer-elim-non-leaf"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-frame-pointer-elim-non-leaf"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { noreturn "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-frame-pointer-elim-non-leaf"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { nounwind readonly "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-frame-pointer-elim-non-leaf"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #6 = { noreturn }

!0 = metadata !{metadata !"vtable pointer", metadata !1}
!1 = metadata !{metadata !"Simple C/C++ TBAA"}
!2 = metadata !{metadata !"_ZTSSt12_Ios_Iostate", metadata !3}
!3 = metadata !{metadata !"omnipotent char", metadata !1}
!4 = metadata !{metadata !"any pointer", metadata !3}
!5 = metadata !{metadata !"short", metadata !3}
!6 = metadata !{metadata !"int", metadata !3}
!7 = metadata !{metadata !"_ZTS6SDLKey", metadata !3}
