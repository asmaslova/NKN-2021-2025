program queue
    implicit none
    integer :: n, i, count, total
    integer, allocatable :: sequence(:)
    
    ! Вводим количество человек с рублями и полтинниками
    print *, 'Введите n:'
    read *, n
    
    ! Вычислим общее количество возможных очередей
    total = 1
    do i = 1, n
       total = total * (2 * n - i + 1) / i
    end do
  
    count = 0
    allocate(sequence(2 * n))
  
    ! Проходим по всем возможным последовательностям
    call generate_sequences(n, n, sequence, 1, count)
    
    ! Подсчёт вероятности
    print *, 'Количество подходящих очередей:', count
    print *, 'Общее количество очередей:', total
    print *, 'Вероятность:', real(count) / real(total)
    
    deallocate(sequence)
    
  contains
  
    ! Рекурсивная процедура для генерации всех возможных последовательностей
    recursive subroutine generate_sequences(ones, minus_ones, sequence, pos, count)
      integer, intent(in) :: ones, minus_ones, pos
      integer, intent(inout) :: count
      integer, intent(inout) :: sequence(:)
      integer :: i, sum
      
      ! Если больше нет оставшихся элементов, проверяем траекторию
      if (ones == 0 .and. minus_ones == 0) then
        sum = 0
        do i = 1, size(sequence)
          sum = sum + sequence(i)
          if (sum > 0) return ! Неудачная траектория
        end do
        count = count + 1 ! Успешная траектория
      else
        ! Добавляем 1 (рубль) в последовательность
        if (ones > 0) then
          sequence(pos) = 1
          call generate_sequences(ones - 1, minus_ones, sequence, pos + 1, count)
        end if
        
        ! Добавляем -1 (50 копеек) в последовательность
        if (minus_ones > 0) then
          sequence(pos) = -1
          call generate_sequences(ones, minus_ones - 1, sequence, pos + 1, count)
        end if
        
      end if
    end subroutine generate_sequences
  
  end program queue