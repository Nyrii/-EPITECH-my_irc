int	test()
{
  if (!(list = create_list(NULL, NULL)))
    return (-1);
  list->push_back(list, NULL);
  list->push_back(list, NULL);
  list->push_back(list, NULL);
  list->push_back(list, NULL);
  printf("Size : %d\n", list->get_size(list));
  list->push_back(list, NULL);
  printf("Size : %d\n", list->get_size(list));
  for (i = 0; i < list->get_size(list); i++)
    printf("id : %d\n", list->get_nth(list, i) ? (int)list->get_nth(list, i)->id : -1);
  list->make_circular(list);
  puts("Making it circular");
  for (i = 0; i < list->get_size(list) * 2; i++)
    printf("id : %d\n", list->get_nth(list, i) ? (int)list->get_nth(list, i)->id : -1);

  puts("delete first");
  if (!(list = list->delete_nth(list, 0)))
    return (puterr_int("Error\n", -1));
  printf("Size : %d\n", list->get_size(list));
  for (i = 0; i < list->get_size(list); i++)
    printf("id : %d\n", list->get_nth(list, i) ? (int)list->get_nth(list, i)->id : -1);

  puts("delete second");
  if (!(list = list->delete_nth(list, 1)))
    return (puterr_int("Error\n", -1));
  printf("Size : %d\n", list->get_size(list));
  for (i = 0; i < list->get_size(list); i++)
    printf("id : %d\n", list->get_nth(list, i) ? (int)list->get_nth(list, i)->id : -1);

  puts("insert at 0");
  if (!(list = list->insert_at(list, 0, NULL)))
    return (puterr_int("Error\n", -1));
  printf("Size : %d\n", list->get_size(list));
  for (i = 0; i < list->get_size(list); i++)
    printf("id : %d\n", list->get_nth(list, i) ? (int)list->get_nth(list, i)->id : -1);

  puts("insert at 1");
  if (!(list = list->insert_at(list, 1, NULL)))
    return (puterr_int("Error\n", -1));
  printf("Size : %d\n", list->get_size(list));
  for (i = 0; i < list->get_size(list); i++)
    printf("id : %d\n", list->get_nth(list, i) ? (int)list->get_nth(list, i)->id : -1);

  puts("insert at 0");
  if (!(list = list->insert_at(list, 0, NULL)))
    return (puterr_int("Error\n", -1));
  printf("Size : %d\n", list->get_size(list));
  for (i = 0; i < list->get_size(list); i++)
    printf("id : %d\n", list->get_nth(list, i) ? (int)list->get_nth(list, i)->id : -1);

  puts("insert at 7");
  if (!(list = list->insert_at(list, 7, NULL)))
    return (puterr_int("Error\n", -1));
  printf("Size : %d\n", list->get_size(list));
  for (i = 0; i < list->get_size(list); i++)
    printf("id : %d\n", list->get_nth(list, i) ? (int)list->get_nth(list, i)->id : -1);
  puts("delete 0");
  if (!(list = list->delete_nth(list, 0)))
    return (puterr_int("Error\n", -1));
  printf("Size : %d\n", list->get_size(list));
  for (i = 0; i < list->get_size(list); i++)
    printf("id : %d\n", list->get_nth(list, i) ? (int)list->get_nth(list, i)->id : -1);

  puts("delete 7");
  if (!(list = list->delete_nth(list, 7)))
    return (puterr_int("Error\n", -1));
  printf("Size : %d\n", list->get_size(list));
  for (i = 0; i < list->get_size(list); i++)
    printf("id : %d\n", list->get_nth(list, i) ? (int)list->get_nth(list, i)->id : -1);

  list->destroy(list);
}
