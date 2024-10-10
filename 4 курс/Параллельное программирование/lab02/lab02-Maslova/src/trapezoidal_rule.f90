module trapezoidal_rule
  use iso_fortran_env, only : int32, int64, real32, real64
  use omp_lib
  implicit none

  abstract interface
    ! Абстрактный интерфейс для подынтегральной функции
    pure function f(x)
      double precision, intent(in) :: x
      double precision :: f
    end function f
  end interface

  private
  public :: trapezoidal

contains
  function trapezoidal(func, a, b, n, threads_num) result (res)
    implicit none
    procedure(f) :: func
    real(real64), intent(in) :: a, b
    integer(int64), intent(in) :: n, threads_num
    real(real64) :: res

    real(real64) :: h, x, sum
    integer(int64) :: i

    ! Шаг интегрирования
    h = (b - a) / real(n, real64)

    ! Инициализация суммы
    sum = 0.0_real64

    ! Параллельная область
    !$omp parallel do private(x, i) reduction(+:sum) num_threads(threads_num)
    do i = 1, n-1
      x = a + i * h
      sum = sum + func(x)
    end do
    !$omp end parallel do

    ! Окончательное значение интеграла
    res = h * (0.5 * (func(a) + func(b)) + sum)
  end function trapezoidal
end module trapezoidal_rule
