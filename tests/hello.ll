target triple = "i386-pc-linux-gnu"

@.str = private constant [15 x i8] c"hello, world!\0A\00"

define i32 @main() {
entry:
  %str = getelementptr inbounds [15 x i8]* @.str, i32 0, i32 0
  %call = call i32 (i8*, ...)* @printf(i8* %str)
  ret i32 1
}

declare i32 @printf(i8*, ...)
