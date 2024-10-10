program dice_probability
    implicit none
    integer :: n_trials, i
    integer :: count_8, count_even, die1, die2
    real :: probability_A_given_B
    real :: rand1, rand2  ! Переменные для генерации случайных чисел

    ! Задаем количество испытаний
    n_trials = 1000000
    count_8 = 0
    count_even = 0

    ! Генерируем пары случайных чисел и считаем суммы
    do i = 1, n_trials
        call random_number(rand1)
        call random_number(rand2)

        die1 = floor(rand1 * 6) + 1  ! Получаем случайное число от 1 до 6
        die2 = floor(rand2 * 6) + 1  ! Получаем случайное число от 1 до 6

        if ((die1 + die2) == 8) then
            count_8 = count_8 + 1
        end if

        if (mod(die1 + die2, 2) == 0) then
            count_even = count_even + 1
        end if
    end do

    ! Вычисляем условную вероятность P(A|B)
    if (count_even > 0) then
        probability_A_given_B = real(count_8) / real(count_even)
    else
        probability_A_given_B = 0.0
    end if

    ! Выводим результат
    print *, 'Число испытаний: ', n_trials
    print *, 'Число случаев, когда сумма равна 8: ', count_8
    print *, 'Число четных сумм: ', count_even
    print *, 'Вероятность P(A|B): ', probability_A_given_B

end program dice_probability
