program card_simulation
    implicit none
    integer, parameter :: n = 36, n_trials = 1000000
    integer :: deck(n), i, ace_count, ace_given_first_ace_count
    real :: p_a, p_a_given_b

    call random_seed()

    ! Инициализация массива карт: 1-4 — это тузы, 5-36 — остальные карты
    do i = 1, 4
        deck(i) = 1  ! Обозначаем туз как 1
    end do
    do i = 5, n
        deck(i) = 0  ! Остальные карты как 0
    end do

    ace_count = 0
    ace_given_first_ace_count = 0

    ! Основной цикл симуляций
    do i = 1, n_trials
        ! Перемешиваем колоду
        call shuffle(deck, n)

        ! Проверка условий
        if (deck(2) == 1) then
            ace_count = ace_count + 1
        end if
        if (deck(1) == 1 .and. deck(2) == 1) then
            ace_given_first_ace_count = ace_given_first_ace_count + 1
        end if
    end do

    ! Вычисление вероятностей
    p_a = real(ace_count) / real(n_trials)
    p_a_given_b = real(ace_given_first_ace_count) / real(ace_count)

    ! Вывод результатов
    print *, 'P(A) = ', p_a
    print *, 'P(A|B) = ', p_a_given_b

contains

    ! Процедура перемешивания колоды Фишера-Йетса
    subroutine shuffle(array, size)
        integer, intent(inout) :: array(*)
        integer, intent(in) :: size
        integer :: i, j, temp
        real :: r

        do i = size, 1, -1
            call random_number(r)
            j = int(r * i) + 1
            temp = array(i)
            array(i) = array(j)
            array(j) = temp
        end do
    end subroutine shuffle

end program card_simulation