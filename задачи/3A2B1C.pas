Program P;

var 
    f: Text;
    current, next: char;
    count: integer;


begin
    Assign(f, 'file.txt');
    Reset(f);

    if not EOF(f) then
    begin
        Read(f, current);
        count := 1;

        while not EOF(f) do
        begin
            Read(f, next);

            if current = next then
            begin
                inc(count);
            end
            else
            begin
                Write(count, current);
                count := 1;
                current := next;
            end;
        end;

        Write(count, current);
    end;

    Close(f);
end.
