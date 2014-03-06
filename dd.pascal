Var x1,y1,x2,y2,x3,y3,triangles,rights,a,b,c:longint;
  begin
    rights := 0;
    read(triangles);
    while triangles>0 do
      begin
        dec(triangles);
        read(x1,y1,x2,y2,x3,y3);
        a:=(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        b:=(x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
        c:=(x2-x3)*(x2-x3) + (y2-y3)*(y2-y3);
        if (a = b + c or b = a + c or c = a + b) then
        begin
          rights := rights + 1;
        end;   
      end;
      Writeln(rights);
  end. 