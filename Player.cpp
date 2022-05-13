Player::Player(GameVisual* gv, int i, int j) : gv(gv), i(i), j(j)
{
    map = gv->getMap();
    hp = 3;
    armor = 0;
    money = 10;
    number_of_moves = 0;
    treasure = NOTHING;
    detector = 1;
    isShod = false;
    map->getField(i, j)->is_player_here = true;
    map->discoverField(i, j);
    gv->updateStat(number_of_moves, hp, armor);
}

Player::~Player()
{
    map = nullptr;
    gv = nullptr;
}

int Player::check(bool& code)
{
    code = true;
    switch (treasure)
    {
        case TREASURE:
            gv->treasureAnimate(i, j, TREASURE);
            hp = WIN_CODE;
            break;
        case FALSE_TREASURE:
            gv->treasureAnimate(i, j, FALSE_TREASURE);
            break;
        case MINED_TREASURE:
            gv->treasureAnimate(i, j, MINED_TREASURE);
            takeDamage(MINE_DAMAGE);
            break;
        default:
            code = false;
    }
    treasure = NOTHING;
    return code;
}

int Player::move(int action, bool repeat)
{
    bool code; //был ли сделан ход

    map->getField(i, j)->is_player_here = false;
    switch(action)
    {
        case UP:
            if (code = map->getWall(i - 1, j)->isEmpty())
                (i == TOP_BORDER) ? check(code) : (i -= STEP);
            break;
        case DOWN:
            if (code = map->getWall(i + 1, j)->isEmpty())
                (i == BOTTOM_BORDER) ? check(code) : (i += STEP);
            break;
        case LEFT:
            if (code = map->getWall(i, j - 1)->isEmpty())
                (j == LEFT_BORDER) ? check(code) : (j -= STEP);
            break;
        case RIGHT:
            if (code = map->getWall(i, j + 1)->isEmpty())
                (j == RIGHT_BORDER) ? check(code) : (j += STEP);
            break;
        default:
            code = false;
    }
    map->getField(i, j)->is_player_here = true;
    if (code)
    {
        map->discoverField(i, j);
        map->getField(i, j)->activatedBy(this);
        if (!repeat)
            addMove();
        gv->updateStat(number_of_moves, hp, armor);//////////////////////////
        gv->draw();
        if (!repeat && isShod)
        {
            std::cout << "Press the same key to repeat the move\n";
            if (action == (int)getch())
                move(action, true);
        }
        return action;
    }

    if (action == PICKUP && treasure == NOTHING)
    {
        //code = true;
        treasure = map->getField(i, j)->getCT();
        map->getField(i, j)->setCT(NOTHING);
        addMove();
        gv->updateStat(number_of_moves, hp, armor);//////////////////////
        gv->draw();
        return action;
    }

    if (action >= '1' && action <= '5')
        code = useItem(action - '1');

    if (code)
    {
        addMove();
        gv->updateStat(number_of_moves, hp, armor);//////////////////
        gv->draw();
    }

    return action;
}

void Player::takeDamage(int damage)
{
    if (damage == MINE_DAMAGE && isShod)
    {
        isShod = false;
        return;
    }
    armor -= damage;
    if (armor < 0)
        hp += armor, armor = 0;
    if (hp < 0)
        hp = 0;
}

std::pair<int, int> Player::getPosition() const
{
    return std::make_pair(i, j);
}

GameVisual* Player::getGV()
{
    return gv;
}

void Player::addMove(int number)
{
    number_of_moves += number;
}

void Player::addArmor(int armor)
{
    this->armor += armor;
}

bool Player::isAlive() const
{
    return (hp > 0);
}

bool Player::isPlaying() const
{
    return (isAlive() && (hp != WIN_CODE));
}


bool Player::useItem(int n)
{
    if (inventory[n].second = 0)
        return false;
    int direction, ii, jj;
    switch(inventory[n].first)
    {
        case CROSSBOW:
            std::cout << "Using the crossbow" << std::endl;
            direction = getch();
            ii = i, jj = j;
            switch(direction)
            {
                case UP:
                    while (map->getWall(ii - 1, jj)->isEmpty() && ii != TOP_BORDER)
                        ii -= 2;
                    gv->itemAnimation(CROSSBOW, i, j, 0, i - ii);
                    map->getWall(ii - 1, jj)->damage(2);
                    break;
                case DOWN:
                    while (map->getWall(ii + 1, jj)->isEmpty() && ii != BOTTOM_BORDER)
                        ii += 2;
                    gv->itemAnimation(CROSSBOW, i, j, 2, ii - i);
                    map->getWall(ii + 1, jj)->damage(2);
                    break;
                case LEFT:
                    while (map->getWall(ii, jj - 1)->isEmpty() && jj != LEFT_BORDER)
                        jj -= 2;
                    gv->itemAnimation(CROSSBOW, i, j, 1, j - jj);
                    map->getWall(ii, jj - 1)->damage(2);
                    break;
                case RIGHT:
                    while (map->getWall(ii, jj + 1)->isEmpty() && jj != RIGHT_BORDER)
                        jj += 2;
                    gv->itemAnimation(CROSSBOW, i, j, 3, jj - j);
                    map->getWall(ii, jj + 1)->damage(2);
                    break;
                default:
                    return false;
            }
            break;
        case BAIT:
            std::cout << "Using the bait" << std::endl;
            direction = getch();
            switch(direction)
            {
                case UP:
                    if (i == TOP_BORDER)
                        return false;
                    gv->itemAnimation(BAIT, i, j, i - 2, j);
                    map->getField(i - 2, j)->activate(gv, i - 2, j);
                    break;
                case DOWN:
                    if (i == BOTTOM_BORDER)
                        return false;
                    gv->itemAnimation(BAIT, i, j, i + 2, j);
                    map->getField(i + 2, j)->activate(gv, i + 2, j);
                    break;
                case LEFT:
                    if (j == LEFT_BORDER)
                        return false;
                    gv->itemAnimation(BAIT, i, j, i, j - 2);
                    map->getField(i, j - 2)->activate(gv, i, j - 2);
                    break;
                case RIGHT:
                    if (j == RIGHT_BORDER)
                        return false;
                    gv->itemAnimation(BAIT, i, j, i, j + 2);
                    map->getField(i, j + 2)->activate(gv, i, j + 2);
                    break;
                default:
                    return false;
            }
            break;
        case HAMMER:
            std::cout << "Using the hammer" << std::endl;
            direction = getch();
            switch(direction)
            {
                case UP:
                    gv->itemAnimation(HAMMER, i, j);
                    return map->getWall(i - 1, j)->damage(1);
                case DOWN:
                    gv->itemAnimation(HAMMER, i, j);
                    return map->getWall(i + 1, j)->damage(1);
                case LEFT:
                    gv->itemAnimation(HAMMER, i, j);
                    return map->getWall(i, j - 1)->damage(1);
                case RIGHT:
                    gv->itemAnimation(HAMMER, i, j);
                    return map->getWall(i, j + 1)->damage(1);
                default:
                    return false;
            }
            break;
        case ROCKET:
            std::cout << "Using the rocket\nThe left top field has (1, 1)" << std::endl;
            std::cout << "Enter vertical coordinates\n";
            ii = 2 * (getch() - '0') - 1;
            std::cout << "Enter horizontal coordinates\n";
            jj = 2 * (getch() - '0') - 1;
            if (ii < 1 || ii > 9 || jj < 1 || jj > 9)
                ii = i, jj = j;

            gv->itemAnimation(ROCKET, ii, jj);
            map->discoverField(ii, jj);
            if (ii != TOP_BORDER)
                map->discoverField(ii - 2, jj);
            if (ii != BOTTOM_BORDER)
                map->discoverField(ii + 2, jj);
            if (ii != LEFT_BORDER)
                map->discoverField(ii, jj - 2);
            if (ii != RIGHT_BORDER)
                map->discoverField(ii, jj + 2);

            break;
        case GRENADE:
            std::cout << "Using the grenade" << std::endl;
            direction = getch();
            switch(direction)
            {
                case UP:
                    if (i == TOP_BORDER)
                        return false;
                    gv->itemAnimation(GRENADE, i, j, i - 2, j);
                    map->destroyField(hp, i - 2, j);
                    break;
                case DOWN:
                    if (i == BOTTOM_BORDER)
                        return false;
                    gv->itemAnimation(GRENADE, i, j, i + 2, j);
                    map->destroyField(hp, i + 2, j);
                    break;
                case LEFT:
                    if (j == LEFT_BORDER)
                        return false;
                    gv->itemAnimation(GRENADE, i, j, i, j - 2);
                    map->destroyField(hp, i, j - 2);
                    break;
                case RIGHT:
                    if (j == RIGHT_BORDER)
                        return false;
                    gv->itemAnimation(GRENADE, i, j, i, j + 2);
                    map->destroyField(hp, i, j + 2);
                    break;
                default:
                    return false;
            }
            break;
        case POTION:
            std::cout << "Using the potion" << std::endl;
            direction = getch();
            switch(direction)
            {
                case UP:
                    if (!(i == TOP_BORDER) && map->getWall(i - 1, j)->isEmpty())
                    {
                        map->discoverField(i - 2, j);
                        gv->itemAnimation(POTION, i, j, i - 2, j);
                    }
                    else
                        gv->itemAnimation(POTION, i, j, -1, -1);
                    hp += 2;
                    if (hp > 3)
                        hp = 3;
                    break;
                case DOWN:
                    if (!(i == BOTTOM_BORDER) && map->getWall(i + 1, j)->isEmpty())
                    {
                        map->discoverField(i + 2, j);
                        gv->itemAnimation(POTION, i, j, i + 2, j);
                    }
                    else
                        gv->itemAnimation(POTION, i, j, -1, -1);
                    hp += 2;
                    if (hp > 3)
                        hp = 3;
                    break;
                case LEFT:
                    if (!(i == LEFT_BORDER) && map->getWall(i, j - 1)->isEmpty())
                    {
                        map->discoverField(i, j - 2);
                        gv->itemAnimation(POTION, i, j, i, j - 2);
                    }
                    else
                        gv->itemAnimation(POTION, i, j, -1, -1);
                    hp += 2;
                    if (hp > 3)
                        hp = 3;
                    break;
                case RIGHT:
                    if (!(j == RIGHT_BORDER) && map->getWall(i, j + 1)->isEmpty())
                    {
                        map->discoverField(i, j + 2);
                        gv->itemAnimation(POTION, i, j, i, j + 2);
                    }
                    else
                        gv->itemAnimation(POTION, i, j, -1, -1);
                    hp += 2;
                    if (hp > 3)
                        hp = 3;
                    break;
                case 'm':
                    hp++;
                default:
                    return false;
            }
            break;
    }
    inventory[n].second--;
    return true;
}