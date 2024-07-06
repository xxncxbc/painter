Кратко о коде программы:
   Класс Figure представляет собой абстрактный базовый класс для рисования различных геометрических фигур в графической сцене Qt. Основная идея заключается в том, чтобы обеспечить базовый функционал для всех типов фигур, таких как квадраты, овалы и ромбы, с возможностью установки и получения координат, а также обновления отрисовки фигуры при изменении ее положения или размера.
  Класс paint отвечает за создание основного окна приложения, настройку сцены для рисования и обработку событий, таких как изменение размеров окна, выбор цвета, выбор типа фигуры, сохранение и открытие файлов. 
    Класс paintScene отвечает за обработку событий мыши и управление фигурами на сцене. В зависимости от типа выбранной фигуры (квадрат, ромб, овал) создается соответствующий объект, который добавляется на сцену. Также реализована возможность отмены последнего действия .
  Классы Oval, Romb и Square наследуют от Figure и реализуют метод paint(), который отвечает за отрисовку овала, ромба и квадрата, соответственно. Конструкторы принимают начальную точку и цвет заливки, устанавливая их для соответствующих фигур.
