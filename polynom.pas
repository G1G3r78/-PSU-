Program P;

type Polynom = record
    coef: integer; //знач.
    step: integer; //степень
    next: Polynom; //указатель на след. элемент
end;

procedure add(var head1: Polynom; var head2: Polynom);
var
    p1, p2, prev, vspom: Polynom;
begin
    p1 := head1^.next; //первый элемент 1 многочлена
    p2 := head2^.next; // первый второго многочлена
    prev := head1; //хранит предыдущий относительно p1

    while (p2^.coef <> 0) or (p2^.step <> 0) do
    begin
        { 1) случай - степень первого больше второго - дальше только по первому}
        if (p1^.step > p2^.step) then
        begin
            prev := p1;
            p1 := p1^.next;
        end;
        { 2) случай - тогда записать узел из второго в первый многочлен}
        else if (p1^.step < p2^.step) then
        begin
            new(vspom);
            vspom^.coef := p2^.coef;
            vspom^.step := p2^.step;
            vspom^.next := p1;
            prev^.next := vspom;
        end;
        {степени равны - сложить коэф-ы и при 0 удалить}
        else 
        begin
            p1^.coef += p2^.coef;
            if (p1^.coef = 0) then
            begin
                vspom := p1;
                prev^.next := p1^.next;
                p1 := p1^.next;
                dispose(vspom);
            end;
            else
            begin
                prev := p1;
                p1 := p1^.next;
            end;    
        end;
    end;
end;