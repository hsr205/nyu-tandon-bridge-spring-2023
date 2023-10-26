 { This is a Pascal program. }

procedure PrintArray(arr: array of Integer);
var
  i: Integer;
begin
  writeln('Elements of the integer array:');
  for i := 0 to High(arr) do
    writeln('Element ', i + 1, ': ', arr[i]);
end;


begin
  MyArray := (10, 20, 30, 40, 50);

end.
