namespace Source2Toolkit.SchemaGen;

public record SchemaEnum(
    int Align,
    IReadOnlyList<SchemaEnumItem> Items);

